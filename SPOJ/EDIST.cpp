#include <bits/stdc++.h>
#define sc(i) scanf("%d",&i)
#define pr(i) printf("%d\n",i)
using namespace std;

int main()
{
    int t;
    sc(t);
    while(t--)
    {
        string sa,sb;
        cin>>sa;
        cin>>sb;
        int cnt = min(sb.size(),sa.size());
        for(int i=0; i<min(sb.size(),sa.size()); i++)
            if(sa[i] == sb[i])
                cnt--;
        int diff = sa.size()-sb.size();
        cout<<cnt+abs(diff)<<endl;
    }
}
