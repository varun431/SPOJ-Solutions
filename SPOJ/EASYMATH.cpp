#include <bits/stdc++.h>
#define max 10000007
#define pb push_back
#define sf scanf
#define pf printf
#define ll long long
using namespace std;

vector<bool> mark();

inline ll read()
{
    ll input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

inline void write(ll n)
{
    char out[32],i=0;
    if(n==0)
        putchar('0');
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

void sieve()
{
    for(int i=n; i<=m; i++)
    {

    }
}

int main()
{
    int t;
    t = read();
    while(t--)
    {
        ll n,m,a,d;
        n = read(), m = read(), a = read(), d = read();

    }
}
