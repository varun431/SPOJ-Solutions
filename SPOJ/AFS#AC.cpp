#include <bits/stdc++.h>
#define LL unsigned long long
#define max 1000000
using namespace std;
LL ans[max];
LL pre[max];

void opt_sieve()
{
    LL i,j,sqt = sqrt(max)+1;
    for(i=2;i<=(max/2);i++)
    {
        for(j=i+i;j<=max;j+=i)
        {
            pre[j] += i;
        }
    }
}

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
            ans[i] = ans[i-1] + pre[i]+1;
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
    while(t--)
    {
        LL n;
        n = read();
        write(a(n));
    }
}
