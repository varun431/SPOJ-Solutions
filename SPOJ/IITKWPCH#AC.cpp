#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        ull pair=0;
        scanf("%d",&n);
        int dig[1100]={0};
        ull input;
        while(n--)
        {
            int num=0;
            scanf("%llu",&input);
            while(input)
            {
                num = num | 1<<(input%10);
                input/=10;
            }
            dig[num]++;
        }
        for(int i=1;i<1024;i++)
        {
            for(int j=i+1;j<1024;j++)
            {
                if(i&j)
                    pair = pair + dig[i]*dig[j];
            }
        }
        for(int i=1; i<1024; i++)
        {
            pair = pair + (dig[i]-1)*(dig[i])/2;
        }
        printf("%llu\n",pair);
    }
}
