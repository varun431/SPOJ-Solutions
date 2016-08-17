#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {
        int n;
        scanf("%d",&n);
        if(!n)
        {
            printf("Case %d: 0\n",j+1);
            continue;
        }
        int mon[n];
        ll dp[n];
        for(int i=0; i<n; i++)
            scanf("%d",&mon[i]);
        dp[0] = mon[0];
        if(n>1)
            dp[1] = max(mon[1],mon[0]);
        for(int i=2; i<n; i++)
            dp[i] = max(dp[i-2]+mon[i], dp[i-1]);
        printf("Case %d: %lld\n",j+1,dp[n-1]);
    }
}
