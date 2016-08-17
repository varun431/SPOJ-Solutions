#include <bits/stdc++.h>
#define ll long long
#define max 10000
using namespace std;

vector<bool> mark(max,true);
vector<int> prime;

void sieve()
{
    prime.push_back(2);
    mark[1] = false;
    for(int i=3; i<=sqrt(max); i+=2)
        if(mark[i])
            for(int j=i*i; j<=max; j+=2*i)
                mark[j] = false;
    for(int i=3; i<max; i+=2)
        if(mark[i])
            prime.push_back(i);
}

ll read()
{
    ll input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

void write(ll n)
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

long long mul(long long a,long long b,long long c);
long long mod(long long a,long long b,long long c){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=mul(x,y,c);
        }
        y = mul(y,y,c);
        b /= 2;
    }
    return x%c;
}

long long mul(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

int Miller(long long p,long long it){
    if(p<2){
        return 0;
    }
    if(p!=2 && p%2==0){
        return 0;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    long long i;
    for(i=0;i<it;i++){
        long long a=rand()%(p-1)+1,tt=s;
        long long md=mod(a,tt,p);
        while(tt!=p-1 && md!=1 && md!=p-1){
            md=mul(md,md,p);
            tt *= 2;
        }
        if(md!=p-1 && tt%2==0){
            return 0;
        }
    }
    return 1;
}

bool isperfectsquare(ll n)
{
    ll sqt = sqrt(n);
    return n == sqt*sqt;
}

ll divcnt(ll n)
{
    ll ans=1,count;
    int i=0;
    for(int p=prime[i];;i++)
    {
        if(p*p*p > n)
            break;
        count = 1;
        while(n%p==0)
        {
            n = n/p;
            count = count+ 1;
        }
        ans *= count;
    }
    if(Miller(n, 20))
        ans *= 2;
    else if(isperfectsquare(n) && Miller(sqrt(n), 20))
        ans *= 3;
    else if(n!=1)
        ans *= 4;
    return ans;
}

int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,ans=0;
        n = read();
        for(int i=1; i<n; i++)
            ans += divcnt(i*i);
        write(ans);
    }
}
