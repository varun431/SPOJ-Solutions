#include <bits/stdc++.h>
#define max 10000007
#define pb push_back
#define sf scanf
#define pf printf
#define ll int
using namespace std;

int small=INT_MAX,large=INT_MIN;

inline ll read()
{
    ll input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

inline void write(ll n)
{
    char out[32],i=0;
    if(n==0)
        putchar('0');
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

class survivor
{
    public:
        int rank;
        int size;
        survivor *parent;
        survivor(): rank(0),
                    size(1),
                    parent(this) { }
};

survivor* Find(survivor* x)
{
    if(x->parent != x)
        x->parent = Find(x->parent);
    return x->parent;
}

void Union(survivor* x, survivor* y)
{
    survivor* xRoot = Find(x->parent);
    survivor* yRoot = Find(y->parent);
    if(xRoot == yRoot)
        return;
    if(xRoot->rank > yRoot->rank)
    {
        yRoot->parent = xRoot;
        xRoot->size += yRoot->size;
        yRoot->size = 0;
        if(large < xRoot->size)
            large = xRoot->size;
    }
    else if(xRoot->rank < yRoot->rank)
    {
        xRoot->parent = yRoot;
        yRoot->size += xRoot->size;
        xRoot->size = 0;
        if(large < yRoot->size)
            large = xRoot->size;
    }
    else
    {
        yRoot->parent = xRoot;
        xRoot->rank++;
        xRoot->size += yRoot->size;
        yRoot->size = 0;
        if(large < xRoot->size)
            large = xRoot->size;
    }
}

int main()
{
    int n,q,a,b;
    n = read(), q = read();
    survivor** surv = new survivor*[n+1];
    for(int i=0; i<=n; i++)
        surv[i] = new survivor();
    for(int j=0; j<q; j++)
    {
        a = read(), b = read();
        Union(surv[a], surv[b]);
        for(int i=1; i<=n; i++)
        {
            //cout<<surv[i]->size<<" size\n";
            if(surv[i]->size != 0)
            {
                /*if(surv[i]->size > large)
                    large = surv[i]->size;*/
                if(surv[i]->size < small)
                    small = surv[i]->size;
            }
        }
        write(large - small);
        small=INT_MAX;
    }
}
