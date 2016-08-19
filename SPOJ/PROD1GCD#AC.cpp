#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

const int lim = 15000001;
bool mark[lim];
vector<int> prime;

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

ll check(ll a, ll b) {
    ll tmp = a*b;
    if(tmp>=mod) return tmp%mod;
    return tmp;
}

ll power(ll base, ll exp) {
    ll result=1;
    while(exp>0) {
        if(exp&1)
            result=check(base,result);
        base = check(base,base);
        exp >>= 1;
    }
    return result;
}

void sieve() {
    prime.push_back(2);
    for(ll i=3; i<lim; i+=2) {
        if(!mark[i]) {
            for(ll j=i*i; j<lim; j+=(2*i)) {
                mark[j]=true;
            }
            prime.push_back(i);
        }
    }
}

int main() {
    sieve();
    int t;
    t=read();
    while(t--) {
        int n,m;
        n=read(), m=read();
        ll res=1;
        int temp = max(m,n);
        m = min(m,n), n = temp;
        for(auto it=prime.begin(); it!=prime.end(); it++) {
            ll tmp = *it, ans=0;
            if(tmp>m)
                break;
            while(m/tmp) {
                ans+=(m/tmp)*(n/tmp);
                tmp*=(*it);
            }
            res=check(res, power((*it), ans));
        }
        write(res);
    }
}
