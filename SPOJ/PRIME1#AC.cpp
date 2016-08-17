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
	prime = new long long int[50000];
	prime[0] = 2;
	mark = new bool[50000];
	mark = (bool*)memset(mark,0,50000);
	mark[0]=1;
	for(i=3;i<=50000;i+=2)
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

int main()
{
    int t;
    long long int a,b;
	cin>>t;
	sieve();
	while(t--)
	{
	    long long int i,w;
	    int z=0,sqt;
		cin>>a>>b;
		//cout<<mark[5]<<"  "<<mark[8]<<"\n";
		if(a%2==0)
			w=a+1;
		else
			w=a;
		if(a==1 || a==2)
			cout<<2<<"\n";
		for(i=w;i<=b;i=i+2)
		{
			z=0;
			bool isprime=true;
			sqt = sqrt(i) + 1;
			while(sqt > prime[z])
            {
                if(i%prime[z]==0)
                {
                    isprime=false;
                    break;
                }
                z++;
            }
            if(isprime && i>1)
                cout<<i<<"\n";
		}
		//mark = (bool*)memset(mark,0,b/2);
	}
}
