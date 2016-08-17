#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
map<ull, ull> value;

ull coins(ull num)
{
    if(num == 0)
        return num;
    if(value[num] == 0)
    {
        value[num] = max(num, coins(num/2)+coins(num/3)+coins(num/4));
    }
    return value[num];
}

int main()
{
    ull num;
    while(scanf("%llu",&num)!=EOF)
    {
        printf("%llu\n",coins(num));
    }
}
