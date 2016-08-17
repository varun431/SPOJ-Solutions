#include <bits/stdc++.h>

using namespace std;

int last_dig(unsigned long long n)
{
    int tens = (n/10)%10;
    if(n<10)
    {
        int arr[10]={1,1,2,6,4,2,2,4,2,8};
        return arr[n];
    }
    if(tens & 1)
    {
        return (4*last_dig(n/5)*last_dig(n%10))%10;
    }
    else
    {
        return (6*last_dig(n/5)*last_dig(n%10))%10;
    }
}

int main()
{
    unsigned long long n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",last_dig(n));
    }
}
