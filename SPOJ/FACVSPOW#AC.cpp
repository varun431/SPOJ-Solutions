#include <bits/stdc++.h>
using namespace std;

int res[1000001];

inline void factvspow()
{
    double fact=0.0,pow=0.0;
    int j=1;
    for(int i=2; i<=1000000; i++)
    {
        while(1)
        {
            j++;
            fact += log(j);
            pow = j*log(i);
            if(fact > pow)
            {
                res[i]=j;
                break;
            }
        }
    }
}

int main()
{
    factvspow();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a;
        scanf("%d",&a);
        printf("%d\n",res[a]);
    }
}
