#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        if((n/i) < i)
            break;
        ans += ((n/i) - i + 1);
    }
    printf("%d\n",ans);
}
