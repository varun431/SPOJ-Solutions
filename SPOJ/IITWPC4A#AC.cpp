#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline int read()
{
    int input = 0;
    char c = getchar();
    for(;c>='0' && c<='9'; c=getchar())
        input = (input<<3) + (input<<1) + (c&15);
    return input;
}

inline void write(ll n)
{
    char out[32];
    ll i=0;
    while(n!=0)
    {
        out[i++] = n%10 + '0';
        n = n/10;
    }
    while(i!=0)
        putchar(out[--i]);
}

int main()
{
    int t,m,n;
    t = read();
    while(t--)
    {
        char s[100007];
        gets(s);
        ll cnt = 0,max,min,actual_size,len = strlen(s);
        s[len] = '&';
        map<int,int> times;
        m = read(), n = read();
        if(m==n)
        {
            write(len);
            putchar(' ');
            write(len);
            putchar('\n');
            continue;
        }
        actual_size = len;
        for(int i=0; i<=len; i++)
        {
            if(s[i] == 'a')
                cnt++;
            else
            {
                actual_size += (n-m)*(cnt/m);
                cnt=0;
            }
        }
        if(m>n)
        {
            min = actual_size;
            max = len;
        }
        else
        {
            max = actual_size;
            min = len;
        }
        write(min);
        putchar(' ');
        write(max);
        putchar('\n');
    }
}
