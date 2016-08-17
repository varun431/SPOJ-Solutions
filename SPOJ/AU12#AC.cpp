#include <bits/stdc++.h>
#define max 32000
using namespace std;
#define gP(n) (mark[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (mark[n>>6]&=~(1<<((n>>1)&31)))
unsigned int mark[max/64];
vector<unsigned int> prime;

void opt_sieve()
{
    memset(mark,-1,sizeof(mark));
    prime.push_back(2);
    unsigned int i,j,sqt = sqrt(max)+1;
    for(i=3;i<sqt;i+=2)
        if(gP(i))
        {
            unsigned int i2 = i<<1;
            for(j=i*i;j<max;j+=i2)
                rP(j);
        }
    for(i=3;i<max;i+=2)
        if(gP(i))
            prime.push_back(i);
}

int main()
{
    opt_sieve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned int n,num,i;
        scanf("%u",&n);
        num=n;
        while(num++)
        {
            //printf("Hi\n");
            int flag=1;
            for(i=0;prime[i]*prime[i]<=num;i++)
            {
                if(num%prime[i]==0)
                {
                    //printf("Hi\n");
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                printf("%u\n",num);
                break;
            }
        }
    }
}
