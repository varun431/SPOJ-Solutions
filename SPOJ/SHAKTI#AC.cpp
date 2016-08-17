#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}


int main()
{
    int t;
    string even = "Thankyou Shaktiman" , odd = "Sorry Shaktiman";
    t = read();
    while(t--)
    {
        int n;
        n = read();
        if(!(n&1))
            for(int i=0; i<even.size(); i++)
                putchar(even[i]);
        else
            for(int i=0; i<odd.size(); i++)
                putchar(odd[i]);
        putchar('\n');
    }
}
