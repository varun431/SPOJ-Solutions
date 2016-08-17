#include <bits/stdc++.h>
#define max 10000
using namespace std;

vector<int> prime;
vector<bool> mark(max);

inline void sieve()
{
    mark[1] = true;
    for(int i=3; i*i<=max; i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i; j<=max; j+=2*i)
                mark[j] = true;
        }
    }
    for(int i=3; i<=max; i+=2)
        if(!mark[i])
            prime.push_back(i);
}

inline int pow(int i)
{
    int temp=1;
    for(int j=0; j<i; j++)
        temp *= 10;
    return temp;
}

int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,b,p=-1,dig,temp,flag=0;
        scanf("%d",&n);
        dig = (int)log10(n);
        temp = pow(dig+1)-1;
        b = abs(temp-2*n);
        if(b==1)
        {
            printf("-1\n");
            continue;
        }
        for(int i=0; prime[i]*prime[i]<=b; i++)
        {
            if(b%prime[i] == 0)
            {
                printf("%d\n",prime[i]);
                flag=1;
                break;
            }
        }
        if(!flag)
            printf("%d\n",b);
    }
}
