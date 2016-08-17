#include <bits/stdc++.h>
using namespace std;

long long int euclid(long long int a,long long int b)
{
    if(a%b==0)
        return b;
    return euclid(b,a%b);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,gcd1,prod=1;
        scanf("%lli",&n);
        for(i=1;i<n;i++)
        {
            gcd1 = euclid(n,i);
            //printf("%lli\n",gcd);
            if(gcd1==1)
            {
                prod = (prod*(i%n))%n;
            }
        }
        printf("%lli\n",prod);
    }
}
