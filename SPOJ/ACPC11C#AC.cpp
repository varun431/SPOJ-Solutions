#include <bits/stdc++.h>
#define LL unsigned long long
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        unsigned int n,sum=0,l=0,r,ans = 10000000000,dis;
        scanf("%u",&n);
        unsigned int arr[n];
        for(unsigned int i=0; i<n; i++)
        {
            scanf("%u", &arr[i]);
            sum += arr[i];
        }
        for(unsigned int i=0 ;i<n ; i++)
        {
            r = sum - l - arr[i];
            if(r<l)
                dis = 2*r + l;
            else
                dis = 2*l + r;
            ans = min(ans, dis);
            l += arr[i];
        }
        printf("%u\n",ans);
    }
}
