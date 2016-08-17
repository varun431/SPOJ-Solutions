#include <bits/stdc++.h>
#define sc(a) scanf("%d",&a)
#define scd(a,b) scanf("%d %d",&a,&b)
#define pr(i) printf("%d ",i)
#define loop(i,n) for(int i = 0; i < n; i++)
using namespace std;

class graph
{
    int v;
    vector<int> mark;
    vector<int> *gra;
public:
    graph(int v)
    {
        this->v = v;
        gra = new vector<int>[v+1];
    }

    void mark_init()
    {
        mark.assign(v+1,0);
    }

    void add_edge(int v,int e)
    {
        gra[v].push_back(e);
    }

    void dfs(int v)
    {
        mark[v] = 1;
        pr(v);
        loop(i,gra[v].size())
        {
            if(mark[gra[v][i]] == 0)
            {
                dfs(gra[v][i]);
            }
        }
    }

    void bfs(int v)
    {
        mark[v] = 1;
        queue<int> que;
        que.push(v);
        pr(v);
        while(!que.empty())
        {
            v = que.front();
            loop(i,gra[v].size())
            {
                if(mark[gra[v][i]] == 0)
                {
                    mark[gra[v][i]] = 1;
                    que.push(gra[v][i]);
                    pr(gra[v][i]);
                }
            }
            que.pop();
        }
        printf("\n");
    }
};

int main()
{
    int t,v,s,c,len,ele,adj,edge;
    sc(t);
    c=t;
    while(t--)
    {
        sc(len);
        graph* g = new graph(len);
        loop(i,len)
        {
            scd(ele,adj);
            loop(j,adj)
            {
                sc(edge);
                g->add_edge(ele,edge);
            }
        }
        printf("graph %d\n",(c-t));
        while(true)
        {
            scd(v,s);
            if(v==0 && s==0)
            {
                break;
            }
            if(s)
            {
                g->mark_init();
                g->bfs(v);
            }
            else
            {
                g->mark_init();
                g->dfs(v);
                printf("\n");
            }
        }
        delete g;
    }
}