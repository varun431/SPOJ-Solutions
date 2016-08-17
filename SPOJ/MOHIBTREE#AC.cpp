#include <bits/stdc++.h>
#define max 10000007
#define pb push_back
#define sf scanf
#define pf printf
#define ll long long
using namespace std;

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

ll mul(ll a,ll b,ll c);
ll mod(ll a,ll b,ll c){
    ll x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=mul(x,y,c);
        }
        y = mul(y,y,c);
        b /= 2;
    }
    return x%c;
}

ll mul(ll a,ll b,ll c){
    ll x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

int Miller(ll p,ll it){
    if(p<2){
        return 0;
    }
    if(p!=2 && p%2==0){
        return 0;
    }
    ll s=p-1;
    while(s%2==0){
        s/=2;
    }
    ll i;
    for(i=0;i<it;i++){
        ll a=rand()%(p-1)+1,tt=s;
        ll md=mod(a,tt,p);
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

int mark[max];
vector<int> prime;

void sieve()
{
    prime.pb(2);
    for(int i=3; i<3200; i+=2)
        if(!mark[i])
            for(int j=i*i; j<max; j+=2*i)
                if(!mark[j])
                    mark[j] = 1;
    for(int i=3; i<max; i+=2)
        if(!mark[i])
            prime.pb(i);
}

inline int smallprime(ll n)
{
    int sqt = sqrt(n);
    for(int i=0; prime[i]<=sqt; i++)
        if(n%prime[i] == 0)
            return prime[i];
}

inline ll mohib(ll n)
{
    int smallp;
    ll ans=0;
    if(Miller(n,20))
        return 0;
    if(!(n&1))
        smallp = 2;
    else
        smallp = smallprime(n);
    ans++;
    n -= smallp;
    ans += n/2 - 1;
    return ans;
}

int main()
{
    sieve();
    int t;
    t = read();
    for(int i=1; i<=t; i++)
    {
        ll n,ans;
        n = read();
        ans = mohib(n);
        //cout<<"Case #"<<i<<": ";
        pf("Case #%d: ",i);
        write(ans);
    }
}
