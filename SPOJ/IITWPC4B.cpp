#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,count=0;;
        scanf("%d",&n);
        int start = ceil(n/2.0)-1;
        int end = ceil(n/3.0);
        for(i=start; i>=end; i--)
        {
            int sum = ceil((n-i)/2.0);
            count = count + (i-sum+1);
        }
        printf("%d\n",count);
    }
}
