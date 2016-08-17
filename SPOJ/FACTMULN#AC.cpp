#include <bits/stdc++.h>
#define maxi 32000
using namespace std;
#define gP(n) (mark[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (mark[n>>6]&=~(1<<((n>>1)&31)))
unsigned int mark[maxi/64];
vector<unsigned int> p;

void opt_sieve()
{
    memset(mark, -1,sizeof(mark));
    p.push_back(2);
    unsigned int i,j,sqt = sqrt(maxi)+1;
    for(i=3;i<sqt;i+=2)
        if(gP(i))
        {
            unsigned int i2 = i<<1;
            for(j=i*i;j<maxi;j+=i2)
                rP(j);
        }
    for(i=3;i<maxi;i+=2)
        if(gP(i))
            p.push_back(i);
}


inline unsigned int check(unsigned int n,unsigned int p)
{
    unsigned int ans=0,loop=p;
    while(n/loop!=0)
    {
        ans += int(n/loop);
        loop *= p;
    }
    return ans;
}

int main()
{
    opt_sieve();
    unsigned int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned int n,i,j,temp,count,res,ans=0,sqt;
        scanf("%u",&n);
        temp = n;
        if(n==2)
        {
            printf("2\n");
            continue;
        }
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        sqt = sqrt(n);
        for(i=0; p[i] <= sqt; i++)
        {
            if(temp%p[i]!=0)
                continue;
            res = 0;
            count = 0;
            while(temp%p[i]==0)
            {
                count++;
                temp /= p[i];
            }
            j=p[i];
            while(1)
            {
                res += check(j,p[i]);
                if(res>=count)
                    break;
                j++;
            }
            ans = max(j,ans);
        }
        if(temp>2)
        {
            count++;
            ans = max(temp,ans);
        }
        printf("%u\n",ans);
    }
}
