#include <iostream>
#include <math.h>
#include <string.h>
#define mod 1000000007
#define max 100005
using namespace std;

bool *mark;
long long int *prime;

void primenum()
{
	long long int i,j;
	int z,sqt,len=0;
	prime = new long long int[max];
	prime[0] = 2;
	mark = new bool[max];
	mark = (bool*)memset(mark,true,max);
	mark[0]=false;
	for(i=3;i<max;i+=2)
	{
	    z=0;
	    sqt = sqrt(i) + 1;
		while(sqt > prime[z])
        {
            if(i%prime[z]==0)
            {
                mark[i]=false;
                break;
            }
            z++;
        }
        if(mark[i])
        {
            prime[++len]=i;
        }
	}
}

int main()
{
    primenum();
    int t;
    long long int i,power,total,n,loop;
    cin>>t;
    while(t--)
    {
        cin>>n;
        i=0;
        total=1;
        //cout<<"Hi\n";
        while(prime[i]<=n)
        {
            //cout<<prime[i]<<"\n";
            power=1;
            loop = prime[i];
            while(n/loop!=0)
            {
                power = power + (n/loop);
                loop = loop*prime[i];
            }
            i++;
            //cout<<power<<"\n";
            total = ((total%mod)*(power%mod))%mod;
        }
        cout<<total<<"\n";
    }
}
