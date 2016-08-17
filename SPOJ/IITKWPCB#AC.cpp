#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

/*long long int euclid(long long int a,long long int b)
{
    if(a%b == 0)
        return b;
    return euclid(b,a%b);
}*/

int main()
{
    long long int n,b,i,gcd1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lli",&n);
        b = floor(n/2);
        if(n == 0)
        {
            printf("%lli\n",b);
            continue;
        }
        else if(b == 0)
        {
            printf("lli\n",n);
            continue;
        }
        for(i=b;i>0;i--)
        {
            gcd1 = __gcd(n,i);
            if(gcd1 == 1)
            {
                printf("%lli\n",i);
                break;
            }
        }
    }
}
