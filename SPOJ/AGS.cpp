#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;

inline ULL check(ULL a, ULL mod)
{
    if(a>=mod)
        return a%mod;
    return a;
}

inline ULL power(ULL base, ULL n,ULL mod)
{
    ULL res=1;
    while(n>0)
    {
        if(n&1)
        {
            res = check(res*base,mod);
        }
        base = check(base*base,mod);
        n >>= 1;
    }
    return res;
}

/*inline ULL power(ULL base, ULL n)
{
    ULL res=1;
    while(n>0)
    {
        if(n&1)
        {
            res = res*base;
        }
        base = base*base;
        n >>= 1;
    }
    return res;
}*/

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ULL a,d,r,n,mod,ans,po,po1;
        scanf("%lli %lli %lli",&a,&d,&r);
        scanf("%lli %lli",&n,&mod);
        a = check(a,mod);
        if(r==1)
        {
            n = n>>1;
            ans = check(a+n*d,mod);
        }
        else
        {
            if(n&1)
            {
                n >>= 1;
                po = power(r,n,mod);
                //cout<<po<<"  Value of po\n";
                //ans = ((((a*po)%mod) + ((((r*d)%mod)*(((po-1)/(r-1))%mod))%mod))%mod);
                ans = check(check(a*po, mod) + check(d*r*(po-1)/(r-1), mod), mod);
            }
            else
            {
                n = (n-1) >> 1;
                po = power(r,n,mod);
                po1 = check(po*r, mod);
                //cout<<po<<"  Value of po\n";
                //ans = (((((a*po)%mod) + ((((r*d)%mod)*(((po-1)/(r-1))%mod))%mod))%mod) +d)%mod;
                ans = check(check(a*po, mod) + check(d*(po1-1)/(r-1), mod), mod);
            }
        }
        if(ans<0)
            ans += mod;
        printf("%lli\n",ans);
    }
}
