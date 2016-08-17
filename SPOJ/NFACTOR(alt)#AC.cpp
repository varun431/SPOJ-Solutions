#include <bits/stdc++.h>
#define U unsigned int
#define LL unsigned long long
#define max 1000010
using namespace std;
short mark[max];
U pre[max][11];
//U p[max];

void sieve()
{
    U i,j;
    mark[0]=mark[1]=0;
    for(i=2; i<=max; i+=2)
        mark[i]=1;
    for(i=3; i<=max; i+=2)
    {
        if(!mark[i])
        {
            mark[i]=1;
            for(j=(i<<1); j<=max; j+=i)
            {
                mark[j]++;
            }
        }
    }
    for(i=1; i<=max; i++)
    {
        for(j=0; j<=10; j++)
        {
            pre[i][j] = pre[i-1][j];
            if(mark[i]==j)
                pre[i][j]++;
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
        U a,b,n;
        scanf("%u %u %u",&a,&b,&n);
        printf("%u\n",pre[b][n]-pre[a-1][n]);
    }
}
