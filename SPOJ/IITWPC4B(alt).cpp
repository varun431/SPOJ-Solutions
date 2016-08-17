#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    scanf("%lli",&t);
    while(t--)
    {
        unsigned long int res,n;
        scanf("%llu",&n);
        if(n&1)
        {
            res = round((n+3)*(n+3)/48.0);
            printf("%llu\n",res);
        }
        else
        {
            res = round(n*n/48.0);
            printf("%llu\n",res);
        }
    }
}
