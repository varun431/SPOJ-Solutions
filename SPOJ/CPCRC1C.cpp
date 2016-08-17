#include <bits/stdc++.h>
using namespace std;

inline long long cal(long long n)
{
    long long sum=0;
    while(n!=0)
    {
        sum += n%10;
        n /=10;
    }
    return sum;
}

int main()
{
    while(true)
    {
        long long sum=0,a,b;
        scanf("%lld %lld",&a,&b);
        if(a==-1 && b==-1)
            break;
        for(long i=a; i<=b; i++)
        {
            sum += cal(i);
        }
        printf("%lld\n",sum);
    }
}
