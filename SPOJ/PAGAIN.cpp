#include <iostream>
#include <math.h>
#include <string.h>
#define max 100000000

using namespace std;

bool *mark;
long long int *prime;

void smallPrime()
{
	long long int i,j;
	int z,sqt,len=0;
	prime = new long long int[max];
	prime[0] = 2;
	mark = new bool[max];
	mark = (bool*)memset(mark,0,max);
	mark[0]=1;
	for(i=3;i<max;i+=2)
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
    smallPrime();
    long long int w,i,z,sqt,a;
    int t;
    bool isprime;
    cin>>t;
    while(t--)
    {
        cin>>a;
        if(a%2==0)
            w=a-1;
        else
            w=a-2;
        for(i=w;i>1;i-=2)
        {
            z=0;
            isprime=true;
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
            if(isprime)
            {
                cout<<i<<"\n";
                break;
            }
        }
        if(a==3)
            cout<<2<<"\n";
    }
}
