#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

bool *mark;
long long int *prime;

void sieve()
{
	long long int i,j;
	int z,sqt,len=0;
	prime = new long long int[32000];
	prime[0] = 2;
	mark = new bool[32000];
	mark = (bool*)memset(mark,0,32000);
	mark[0]=1;
	for(i=3;i<=32000;i+=2)
	{
	    z=0;
	    sqt = sqrt(i) + 1;
		while(sqt > prime[z])
        {
            if(i%prime[z]==0)
            {
                mark[i]=1;
                break;
            }
            z++;
        }
        if(!mark[i])
        {
            prime[++len]=i;
        }
	}
}

long long int fun(long long int a,long long int b)
{	//cout<<" m is "<<a<< " n is "<<b<<endl;
	long long int n=(pow(a,b+1)-1)/(a-1);
	return n;
}

int main()
{
	sieve();
	long long int t,a,b,i,j,count,sum,num,cnt,k,z,sqt;
	//cout<<mark[31]<<"\n";
	cin>>t;
	while(t--)
	{
		count=0;
		cin>>a>>b;
		for(i=a;i<=b;i++)
		{
			sum=1;
			num=i;
			//k=1;
			cnt=0;
			while(num%2==0)
            {
                cnt++;
                num=num/2;
            }
            sum=sum*fun(2,cnt);
			for(j=3;j<=sqrt(num);j=j+2)
			{
				cnt=0;
				while(num%j==0)
				{
					cnt++;
					num=num/j;
				}
				sum=sum*fun(j,cnt);
			}
			if(num>2)
			{
				sum=sum*(num+1);
			}
			if(sum%2!=0 && sum!=1)
            {
                if(!mark[sum])
                {
                    count++;
                    cout<<i<<"\n";
                }
            }
            if(i==25)
                cout<<sum<<"\n";
			/*z=0;
			bool isprime=true;
			sqt = sqrt(sum) + 1;
			while(sqt > prime[z])
            {
                if(sum%prime[z]==0)
                {
                    isprime=false;
                    break;
                }
                z++;
            }
            if(isprime && i>1)
                cout<<i<<"\n";*/
		}
		//cout<<count<<"\n";
	}
}
