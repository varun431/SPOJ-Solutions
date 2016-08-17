#include <bits/stdc++.h>
#define LL unsigned long long
#define max 12148001999
using namespace std;
//LL *pre;

LL opt_sieve(LL n)
{
    //pre = new LL[max];
    //pre = (LL*)memset(pre,0,max);
    LL i,j,pre=n-1;
    for(i=2;i<=(n/2);i++)
    {
        for(j=n/(i+1)+1; j<=n/i; j++)
        {
            pre += (i-1)*j;
        }
    }
    return pre;
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
    unsigned int t;
    t = read();
    while(t--)
    {
        LL n;
        n = read();
        write(opt_sieve(n));
    }
}
