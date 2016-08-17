#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v,n,m,path_index;
    int* cnt;
    char **graph;
    bool* visited;
    int* path;
public:
    float prob;
    Graph(int n, int m)
    {
        this->n = n;
        this->m = m;
        cnt = new int[n];
        for(int i=0;i<n;i++)
            cnt[i]=0;
        graph = new char*[n];
        for(int i=0;i<n;i++)
        {
            graph[i] = new char[n];
            graph[i] = (char*)memset(graph[i],'a',n);
        }
    }
    void init()
    {
        visited = new bool[n];
        visited = (bool*)memset(visited,false,n);
        path = new int[n];
        path_index=0;
        prob = 0;
    }
    void add_edge(int u,int v,char label)
    {
        graph[u][v] = label;
        cnt[u]++;
    }
    void query(int s,int t,int denominator)
    {
        visited[s] = true;
        path[path_index++] = s;
        if(s==t)
        {
            compute(denominator);
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(graph[s][i]!='a' && !visited[i])
                {
                    denominator *= cnt[s];
                    query(i,t,denominator);
                }
            }
        }
        path_index--;
        visited[s] = false;
    }
    void compute(int denominator)
    {
        float temp = (1.0/denominator);
        char path_label[path_index-1];
        for(int i=0;i<path_index-1;i++)
        {
            path_label[i] = graph[path[i]][path[i+1]];
        }
        for(int i=0; i<path_index/2; i++)
        {
            if(path_label[0] != path_label[path_index-2-i])
                return ;
        }
        prob += temp;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,u,v,s,t,q;
        char label;
        cin>>n>>m;
        Graph* obj = new Graph(n,m);
        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>label;
            obj->add_edge(u,v,label);
        }
        cin>>q;
        for(int i=0;i<q;i++)
        {
            obj->init();
            cin>>s>>t;
            obj->query(s,t,1);
            printf("%0.6f\n",obj->prob);
        }
    }
}
