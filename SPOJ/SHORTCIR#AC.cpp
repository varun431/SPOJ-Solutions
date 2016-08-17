#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
 
using namespace std;
 
static const int isAnd = 1, isNot = 2, isVar = 4;
 
struct node {
    int t; //type: -1 -> variable, 0 -> and, 1 -> or, 2 -> nand, 3 -> nor
    double p;
    double e;
    vector<node*> c;
};
 
node *R;
map< string , double > M;
vector<string> ex;
char buf[1<<15], tbuf[1<<18];
int len;
 
vector<string> _ex, _op;
void toRPN() {
    _ex.clear(); _op.clear();
    for(int i = 0; i < ex.size(); i++) {
        if(ex[i] == "(") _op.push_back(ex[i]);
        else if(ex[i] == ")") {
            while(!_op.empty() && _op.back() != "(") {
                _ex.push_back(_op.back());
                _op.pop_back();
            }
            _op.pop_back();
        } else if(ex[i] == "or") {
            while(!_op.empty() && (_op.back() == "and" || _op.back() == "not")) {
                _ex.push_back(_op.back());
                _op.pop_back();
            }
            _op.push_back(ex[i]);
        } else if(ex[i] == "and") {
            while(!_op.empty() && _op.back() == "not") {
                _ex.push_back(_op.back());
                _op.pop_back();
            }
            _op.push_back(ex[i]);
        } else if(ex[i] == "not") {
            _op.push_back(ex[i]);
        } else {
            M[ex[i]] = 0;
            _ex.push_back(ex[i]);
        }
    }
    while(!_op.empty()) {
        _ex.push_back(_op.back());
        _op.pop_back();
    }
}
 
vector<node*> ev;
void buildIt() {
    ev.clear();
    for(int i = 0; i < _ex.size(); i++) {
        if(_ex[i] == "not") {
            node *n = ev.back();
            if(n->t & isVar) n->p = 1.0 - n->p;
            else n->t ^= isNot;
        } else if(_ex[i] == "and") {
            node *n = new node;
            n->t = 0;
            n->c.clear();
            n->c.push_back(ev.back()); ev.pop_back();
            n->c.push_back(ev.back()); ev.pop_back();
            ev.push_back(n);
        } else if(_ex[i] == "or") {
            node *n = new node;
            n->t = 1;
            n->c.clear();
            n->c.push_back(ev.back()); ev.pop_back();
            n->c.push_back(ev.back()); ev.pop_back();
            ev.push_back(n);
        } else {
            node *n = new node;
            n->t = -1;
            n->p = M[_ex[i]];
            n->e = 1;
            n->c.clear();
            ev.push_back(n);
        }
    }
    R = ev.back();
}
 
void _removeNot(node *n, bool toNot) {
    if(n->t == -1) {
        if(toNot) n->p = 1.0 - n->p;
        return;
    }
    if(toNot) n->t ^= isNot;
    if(n->t & isNot) {
        n->t ^= (isNot | isAnd);
        _removeNot(n->c[0], true);
        _removeNot(n->c[1], true);
    } else {
        _removeNot(n->c[0], false);
        _removeNot(n->c[1], false);
    }
}
 
void _compressSimple(node *n) {
    if(n->t == -1) return;
    vector<node*> nc;
    for(int i = 0; i < n->c.size(); i++) {
        node *c = n->c[i];
        _compressSimple(c);
        if(c->t == n->t) {
            for(int j = 0; j < c->c.size(); j++) {
                node *cc = c->c[j];
                nc.push_back(cc);
            }
            delete c;
        } else {
            nc.push_back(c);
        }
    }
    n->c = nc;
}
 
void reduceIt() {
    _removeNot(R, false);
    _compressSimple(R);
}
 
void clearIt(node *n) {
    if(n->t == -1) {
        delete n;
        return;
    }
    for(int i = 0; i < n->c.size(); i++) {
        node *c = n->c[i];
        clearIt(c);
    }
    delete n;
}
 
bool cmp0(node *a, node *b) {
    return (a->e / (1.0 - a->p)) < (b->e / (1.0 - b->p));
}
 
bool cmp1(node *a, node *b) {
    return (a->e / a->p) < (b->e / b->p);
}
 
void evalIt(node *n) {
    if(n->t == -1) return;
    if(n->t == 0) {
        for(int i = 0; i < n->c.size(); i++) {
            node *c = n->c[i];
            evalIt(c);
        }
        sort(n->c.begin(), n->c.end(), cmp0);
        double r = n->c.back()->e;
        double pr = n->c.back()->p;
        for(int i = n->c.size() - 2; i >= 0; i--) {
            node *c = n->c[i];
            r *= c->p;
            r += c->e;
            pr *= c->p;
        }
        n->e = r;
        n->p = pr;
    } else {
        assert(n->t == 1);
        for(int i = 0; i < n->c.size(); i++) {
            node *c = n->c[i];
            evalIt(c);
        }
        sort(n->c.begin(), n->c.end(), cmp1);
        double r = n->c.back()->e;
        double pr = 1.0 - n->c.back()->p;
        for(int i = n->c.size() - 2; i >= 0; i--) {
            node *c = n->c[i];
            r *= 1.0 - c->p;
            r += c->e;
            pr *= 1.0 - c->p;
        }
        n->e = r;
        n->p = 1.0 - pr;
    }
}
 
int main() {
    int T;
    cin.getline(buf,1<<15);
    sscanf(buf,"%d",&T);
    while(T--) {
        memset(tbuf,0,sizeof(tbuf));
        cin.getline(buf,1<<15);
        for(int i = 0, j = 0; buf[i] != '\0'; i++) {
            if(buf[i] == '(' || buf[i] == ')') {
                tbuf[j++] = ' ';
                tbuf[j++] = buf[i];
                tbuf[j++] = ' ';
            } else tbuf[j++] = buf[i];
        }
        M.clear();
        ex.clear();
        istringstream inp(tbuf);
        string tok;
        while(inp >> tok) ex.push_back(tok);
        toRPN();
        for(int i = 0; i < M.size(); i++) {
            cin.getline(buf,1<<15);
            istringstream in(buf);
            string v; double p;
            in >> v >> p;
            M[v] = p;
        }
        buildIt();
        reduceIt();
        evalIt(R);
        cout << fixed << setprecision(6) << R->e << endl;
        clearIt(R);
    }
    return 0;
}
 