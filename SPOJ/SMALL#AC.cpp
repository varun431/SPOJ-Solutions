#include <bits/stdc++.h>
#define max 10001
#define ULL unsigned long long
#define mod 1000000007
using namespace std;

bool *mark;
//vector<long int> prime;

void sieve()
{
    int i,j,k=1;
    mark = new bool[max+1];
    mark = (bool*)memset(mark,true,max+1);
    mark[0]=mark[1]=false;
    for(i=2;i*i<=max;i++)
    {
        if(mark[i])
        {
            for(j=i*i;j<=max;j+=i)
            {
                mark[j]=false;
            }
        }
    }
    /*for(i=3;i<max;i+=2)
    {
        if(mark[i])
            prime.push_back(i);
    }*/
}

int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,temp;
        ULL ans=1;
        scanf("%d",&n);
        for(int i=2; i<=n; i++)
        {
            if(!mark[i])
                continue;
            temp=i;
            while(temp <= n)
            {
                ans = (ans*i)%mod;
                temp *= i;
            }
        }
        printf("%llu\n",ans);
    }
}
