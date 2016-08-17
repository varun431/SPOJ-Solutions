#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;

/*unsigned long long fast_pow(unsigned long long base,unsigned long long n,unsigned long long m)
{
	if(n==0) return 1;
	if(n==1) return base;
	unsigned long long ans;
	ans=fast_pow(base,n/2,m);
	ans=(ans*ans)%m;
	if(n%2) ans=ans*base%m;
	return ans;
}*/

inline ULL sum(ULL a, ULL b)
{
    ULL n = b-a+1, value;
    value = n*(a+b);
    return (value/2);
}

int main()
{
    int T;
	unsigned long long ans;
	unsigned long long a,b,n,i,value,sqt,z;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%llu",&n);
		ans=0;
		sqt = sqrt(n);
		for(i=1;i*i<=n;i++)
		{
		    a = n/i, b = (n/(i+1))+1;
			value=sum(b,a);
			ans += ((i-1)*value) + (i*(a-1));
		}
		if(((i-1)*i)>n)
        {
            //z = sqt+1;
            ans -= (i-1)*(a-1);
        }
        /*else
        {
            z = sqt;
        }
		for(i=1;i<z;i++)
        {
            ans += i*((n/i)-1);
        }*/
		printf("%llu\n",ans);
	}
	return 0;
}
