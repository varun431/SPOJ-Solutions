#include <bits/stdc++.h>
#define max 100000000
using namespace std;
#define gP(n) (mark[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (mark[n>>6]&=~(1<<((n>>1)&31)))
unsigned int mark[max/64];
vector<unsigned int> prime;

void opt_sieve()
{
    memset(mark,-1,sizeof(mark));
    prime.push_back(2);
    unsigned int i,j,sqt = sqrt(max)+1;
    for(i=3;i<sqt;i+=2)
        if(gP(i))
        {
            unsigned int i2 = i<<1;
            for(j=i*i;j<max;j+=i2)
                rP(j);
        }
    for(i=3;i<max;i+=2)
        if(gP(i))
            prime.push_back(i);
    prime.push_back(100000007);
}

int main()
{
    opt_sieve();
    int t=1;
    unsigned long long i,power,total,n,loop,mod;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu %llu",&n,&mod);
        i=0;
        total=1;
        while(prime[i]<=n)
        {
            power=1;
            loop = prime[i];
            while(n/loop!=0)
            {
                power = power + (n/loop);
                loop = loop*prime[i];
            }
            i++;
            total = ((total%mod)*(power%mod))%mod;
        }
        printf("%llu\n",total);
    }
}
