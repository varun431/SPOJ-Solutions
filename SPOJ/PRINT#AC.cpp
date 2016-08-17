#include <bits/stdc++.h>
#define max 50000

using namespace std;

bool *mark;
vector<long int> prime;

void sieve()
{
    long int i,j,k=1;
    mark = new bool[max+1];
    mark = (bool*)memset(mark,true,max);
    mark[0]=mark[1]=false;
    prime.push_back(2);
    for(i=3;i*i<=max;i+=2)
    {
        if(mark[i])
        {
            for(j=i*i;j<=max;j+=2*i)
            {
                mark[j]=false;
            }
        }
    }
    for(i=3;i<=max;i+=2)
    {
        if(mark[i])
            prime.push_back(i);
    }
}

int main()
{
    sieve();
    int t;
    bool big[1000001];
    scanf("%d",&t);
    while(t--)
    {
        long int l,u,i,k,j;
        scanf("%li %li",&l,&u);
        memset(big,true,sizeof big);
        for(i=0;prime[i]*prime[i]<=u;i++)
        {
            j=l/prime[i];
            j*=prime[i];
            for(;j<=u;j+=prime[i])
            {
                if(j<l)
                    continue;
                big[j-l] = false;
            }
        }
        for(i=0;prime[i]*prime[i]<=u;i++)
        {
            if(prime[i]>=l && prime[i]<=u)
                printf("%li\n",prime[i]);
        }
        for(i = 0 ; i < u-l+1 ; i++)
        {
            if(big[i])
                printf("%li\n",i+l);
        }
    }
}
