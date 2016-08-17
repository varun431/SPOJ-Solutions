#include <bits/stdc++.h>
#define LL unsigned long long
#define max 10000000
using namespace std;
#define gP(n) (mark[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (mark[n>>6]&=~(1<<((n>>1)&31)))
LL mark[max/64];
vector<LL> prime;
LL ans[10000000];
LL pre[10000000];

void opt_sieve()
{
    memset(mark, -1,sizeof(mark));
    prime.push_back(2);
    long int i,j,sqt = sqrt(max)+1;
    for(i=3;i<sqt;i+=2)
        if(gP(i))
        {
            long int i2 = i<<1;
            for(j=i*i;j<max;j+=i2)
            {
                rP(j);
                if(pre[j]==0)
                    pre[j] = i;
            }
        }
    for(i=3;i<max;i+=2)
        if(gP(i))
            prime.push_back(i);
}

bool checkPrime(LL n){return (n&1)&&gP(n);}

LL a(LL n)
{
    LL i;
    if(n==0 || n==1)
        return 0;
    if(ans[n]==0)
    {
        for(i=2; i<=n; i++)
        {
            if(ans[i]!=0)
            {
                continue;
            }
            if((i&1)==0)
            {
                ans[i] = ans[i-1] + 2;
            }
            else
            {
                if(checkPrime(i))
                    ans[i] = ans[i-1] + i;
                else
                    ans[i] = ans[i-1] + pre[i];
            }
        }
    }
    return ans[n];
}

LL read()
{
    LL input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

void write(LL n)
{
    char out[32],i=0;
    while(n!=0)
    {
        out[i++] = n%10 + '0';
        n /= 10;
    }
    while(i!=0)
    {
        putchar(out[--i]);
    }
    putchar('\n');
}

int main()
{
    opt_sieve();
    unsigned int t;
    t = read();
    //scanf("%u",&t);
    while(t--)
    {
        LL n;
        n = read();
        //scanf("%llu",&n);
        write(a(n));
        //printf("%llu\n",a(n));
    }
}
