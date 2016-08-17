#include <bits/stdc++.h>
#define max 32000000

using namespace std;

long long int *prime;
bool *mark;

void sieve()
{
    long long int i,j,k=0;
    prime = new long long int[max];
    mark = new bool[max];
    mark = (bool*)memset(mark,true,max);
    mark[0]=mark[1]=false;
    for(i=3;i<=sqrt(max);i+=2)
    {
        if(mark[i])
        {
            for(j=i*i;j<max;j=j+i)
            {
                mark[j] = false;
            }
        }
    }
    prime[0] = 2;
    for(i=3;i<max;i+=2)
    {
        if(mark[i])
            prime[++k] = i;
    }
}

int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,count=0,k=1,num,py;
        scanf("%lli",&n);
        num = n;
        while(num%2==0)
        {
            count++;
            num = num/2;
        }
        py = abs(2*count - 1);
        for(i=prime[k];i<=sqrt(num)+1;i=prime[++k])
        {
            count=0;
            while(num%i==0)
            {
                count++;
                num=num/i;
            }
            py = py*(2*count + 1);
        }
        if(num>2)
        {
            py = py*3;
        }
        py = 0.5*(py-1);
        printf("%lli\n",py);
    }
}
