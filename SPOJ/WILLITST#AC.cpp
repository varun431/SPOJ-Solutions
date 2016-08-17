#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;

bool isPowerOfTwo(ULL x)
{
  return x && (!(x&(x-1)));
}

int main()
{
    ULL n;
    scanf("%llu",&n);
    isPowerOfTwo(n)? printf("TAK\n"): printf("NIE\n");
}
