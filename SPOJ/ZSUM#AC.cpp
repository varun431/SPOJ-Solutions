#include <bits/stdc++.h>
#define LL unsigned long long
#define mod 10000007
using namespace std;

inline LL fast_pow(LL base, LL n)
{
	if(n==0) return 1;
	if(n==1) return base;
	LL ans;
	ans = fast_pow(base,n/2);
	ans=(ans*ans)%mod;
	if(n&1) ans=ans*base%mod;
	return ans;
}

inline LL z(LL n, LL k)
{
    LL zf = (fast_pow(n,k)%mod + fast_pow(n,n)%mod + (2*fast_pow(n-1,k))%mod + (2*fast_pow(n-1,n-1))%mod)%mod;
    return zf;
}

int main()
{
    while(true)
    {
        LL n,k,res;
        scanf("%llu %llu", &n, &k);
        if(n == 0 && k == 0)
            break;
        res = z(n,k);
        printf("%llu\n", res);
    }
}
