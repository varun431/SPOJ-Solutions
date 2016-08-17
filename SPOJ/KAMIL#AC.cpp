#include <bits/stdc++.h>
int main()
{
    char c;int v=1;
    while((c=getchar())!=-1)
    {
        if(c=='\n'){printf("%d\n",v);v=1;}

        if(c=='D'||c=='F'||c=='L'||c=='T')
            v*=2;
    }
}
