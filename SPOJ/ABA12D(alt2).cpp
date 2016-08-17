#include <bits/stdc++.h>
#define max 30000000
using namespace std;
#define gP(n) (mark[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (mark[n>>6]&=~(1<<((n>>1)&31)))
long int mark[max/64];
vector<long int> prime;

void opt_sieve()
{
    memset(mark, -1,sizeof(mark));
    prime.push_back(2);
    long int i,j,sqt = sqrt(max)+1;
    for(i=3;i<sqt;i+=2)
        if(gP(i))
        {
            long int i2 = i<<1;
            for(j=i*i;j<max;j+=i2)
                rP(j);
        }
    for(i=3;i<max;i+=2)
        if(gP(i))
            prime.push_back(i);
}
long long int fun(long long int a,long long int b)
{	//cout<<" m is "<<a<< " n is "<<b<<endl;
	long long int n=(pow(a,b+1)-1)/(a-1);
	return n;
}
int main()
{	opt_sieve();
	long long int t,i,j,x;
	scanf("%lld",&t);
	while(t--)
	{
		long long int a,b,sum=1,ans=0,p,m,n;
		scanf("%lld %lld",&a,&b);
		for(i=a;i<=b;i++)
		{	x=i;
			if(di[i]==0)
			{	sum=1;

				if(x%2==0)
				{	p=0;
					m=2;
					while(x%2==0)
					{
						x=x/2;
						p++;
					}
					sum*=fun(m,p);
				}
				//cout<<sum<<" ";
				for(j=3;j<=i;j++)
				{
					if(x%j==0)
					{	p=0;
						m=j;
						while(x%j==0)
						{
							x=x/j;
							p++;
						}
						sum*=fun(m,p);
					}
				}
				di[i]=sum;
			}
			else sum=di[i];
			if(mark[di[i]]==0)
			{	//cout<<sum<<endl;
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
