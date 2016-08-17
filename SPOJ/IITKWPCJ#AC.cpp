#include <bits/stdc++.h>
#define loop(i,n)  for(int i=0; i<n; i++)
using namespace std;

void string_check(string a, string b)
{
    int g = __gcd(a.size(), b.size());
    loop(i,a.size())
    {
        if(a[i] != a[i%g])
        {
            printf("NO\n");
            return;
        }
    }
    loop(i,b.size())
    {
        if(b[i] != a[i%g])
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        string_check(a,b);
    }
}
