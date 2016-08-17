#include<stdio.h>
typedef long long int ll;
int main()
{
    ll n, i, num, result = 0;
    scanf("%lld", &n);
    for(i=0; i< n; i++)
    {
        scanf("%lld", &num);
        result = result ^ num;
    }
    printf("%lld\n", result);
    return 0;
}
