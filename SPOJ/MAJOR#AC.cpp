#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,tmp;
        map<int,int> cnt;
        scanf("%d",&n);
        for(int i=0; i<n ;i++)
        {
            scanf("%d",&tmp);
            cnt[tmp]++;
        }
        int max=0,no;
        for(map<int,int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
        {
            if(it->second > max)
            {
                max = it->second;
                no = it->first;
            }
        }
        if(max > (n/2))
            printf("YES %d\n",no);
        else
            printf("NO\n");
    }
}
