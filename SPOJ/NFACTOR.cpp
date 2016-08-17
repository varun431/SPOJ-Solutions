#include <bits/stdc++.h>
#define U unsigned int
#define LL unsigned long long
#define max 1000001
using namespace std;
bool mark[max];
U p[max];

void sieve()
{
    U i,j;
    memset(mark,true,max);
    mark[0]=mark[1]=false;
    for(i=2; i*i<=max; i++)
    {
        if(mark[i])
        {
            p[i]=i;
            for(j=i*i; j<=max; j+=i)
            {
                if(mark[j])
                {
                    mark[j]=false;
                    p[j] = i;
                }
            }
        }
    }
    for(i=1001; i<=max; i++)
    {
        if(mark[i])
        {
            p[i] = i;
        }
    }
}

int main()
{
    sieve();
    LL t;
    scanf("%llu",&t);
    while(t--)
    {
        U a,b,n,fact,i,count,total=0,temp;
        scanf("%u %u %u",&a,&b,&n);
        for(i=a; i<=b; i++)
        {
            if(i==1 || n==0)
            {
                if(n==0 && i==1)
                {
                    total = 1;
                    break;
                }
                else if(n==0)
                {
                    total = 0;
                    break;
                }
                continue;
            }
            count=1;
            fact=p[i];
            temp = i/fact;
            while(temp!=1 || mark[temp])
            {
                if(p[temp] != fact)
                {
                    count++;
                    fact=p[temp];
                }
                temp /= p[temp];
            }
            if(count==n)
            {
                total++;
            }
        }
        printf("%u\n",total);
    }
}
