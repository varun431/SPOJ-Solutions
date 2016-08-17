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
	mark = new bool[max+1];
	mark = (bool*)memset(mark,0,max+1);
	mark[0]=mark[1]=1;
	for(i=2;i<=sqrt(max);i++)
	{
        if(!mark[i])
        {
            for(j=i*i;j<=max;j=j+i)
            {
                mark[j] = 1;
            }
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
            if(!mark[i])
            {
                cout<<i<<"\n";
                break;
            }
        }
        if(a==3)
            cout<<2<<"\n";
    }
}
