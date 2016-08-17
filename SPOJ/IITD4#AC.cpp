#include <math.h>
#include <stdio.h>
#define LL unsigned long long
#define mod 1000000007

using namespace std;

inline LL fast_pow(LL base,LL n)
{
	int ans = 1;
	while(n>0)
	{
		if(n&1)
		{
			ans = (ans*base)%mod;
		}
		base = (base*base)%mod;
		n >>= 1;
	}
	return ans%mod;
}

inline LL read()
{
    LL input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

inline void write(LL n)
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
	LL ans;
	unsigned int T,a,b,k,i,times;
	scanf("%d\n",&T);
	while(T--)
	{
		a = read(), b = read(), k = read();
		ans=0;
		for(i=1;i<=b;i++)
		{
			times=b/i-(a-1)/i;
			ans=(ans+((LL)times*fast_pow(i,k))%mod)%mod;
		}
		write(ans);
	}
	return 0;
}
