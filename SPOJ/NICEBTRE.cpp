#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int count;
        char nodeType;
        node(){}
        node(char type)
        {
            count = 0;
            nodeType = type;
        }
};

int tree(char str[],int len)
{
    int i = 1,depth = -1,top = -1;
    node* temp = new node[len];
    node* s = new node[len];
    temp[0] = node(str[0]);
    s[++top] = temp[0];
    depth = max(depth,top);
    while(i != len)
    {
        temp[i] = node(str[i]);
        s[++top] = temp[i];
        depth = max(depth,top);
        if(str[i] == 'l')
        {
            s[--top].count++;
            while(top != -1 && s[top].count == 2)
            {
                s[--top].count++;
            }
        }
        i++;
    }
    return depth;
}

int main()
{
    int t,depth;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        depth = tree(str,strlen(str));
        cout<<depth<<"\n";
    }
}
