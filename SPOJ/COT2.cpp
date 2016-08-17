#include <bits/stdc++.h>
using namespace std;

class graph
{
    int n;
    vector<int> weight;
    vector<int> *gra;
    vector<int> mark;
    vector<int> path;
    map<int,int> cmpw;
public:
    graph(int n)
    {
        this->n = n;
        gra = new vector<int>[n];
    }
    void mark_init()
    {
        mark.assign(n,0);
    }
    void add_weight(vector<int> w)
    {
        weight = w;
    }
    void add_edge(int u, int v)
    {
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    /*bool isThere(int v)
    {
        for(int i=0; i<path.size(); i++)
            if(path[i] == v)
                return true;
        return false;
    }*/
    void dfs(int v, int endv)
    {
        path.push_back(v);
        mark[v] = 1;
        if(v == endv)
            for(int j=0; j<path.size(); j++)
                cmpw[weight[path[j]]] = 1;
        else
            for(int i=0; i<gra[v].size(); i++)
                if(!mark[gra[v][i]])
                    dfs(gra[v][i],endv);
        path.pop_back();
        mark[v] = 0;
    }
    int dfsutil(int v, int endv)
    {
        dfs(v,endv);
        int ans = cmpw.size();
        cmpw.clear();
        return ans;
    }
};

int read()
{
    int input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

void write(int n)
{
    char out[32],i=0;
    while(n!=0)
    {
        out[i++] = n%10 + '0';
        n /= 10;
    }
    while(i!=0)
    {
        putchar(out[--i]);
    }
    putchar('\n');
}

int main()
{
    int n,m,u,v;
    //scanf("%d %d",&n,&m);
    n = read(), m = read();
    vector<int> w(n);
    graph *g = new graph(n);
    for(int i=0; i<n; i++)
        w[i] = read();
        //scanf("%d",&w[i]);
    g->add_weight(w);
    for(int i=0; i<n-1; i++)
    {
        //scanf("%d %d",&u,&v);
        u = read(), v = read();
        g->add_edge(u-1,v-1);
    }
    g->mark_init();
    for(int i=0; i<m; i++)
    {
        //scanf("%d %d",&u,&v);
        u = read(), v = read();
        int res = g->dfsutil(u-1,v-1);
        //printf("%d\n",res);
        write(res);
    }
}
