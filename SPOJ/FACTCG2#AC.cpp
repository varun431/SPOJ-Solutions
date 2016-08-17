#include <bits/stdc++.h>
#define max 10000007
using namespace std;

int prime[max] = {0};

void sieve()
{
    for(int i=3; i<3200; i+=2)
        if(prime[i]==0)
            for(int j=i*i; j<max; j+=2*i)
                if(prime[j]==0)
                    prime[j] = i;
}

int read()
{
    int input=0;
    char c = getchar_unlocked();
    for(; c>='0' && c<='9'; c=getchar_unlocked())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

void write(int n)
{
    char out[32],i=0;
    while(n!=0)
    {
        out[i++] = n%10 + '0';
        n /= 10;
    }
    while(i!=0)
    {
        putchar(out[--i]);
    }
}

int main()
{
    sieve();
    int n;
    while((n = read()) != '\0')
    {
        putchar_unlocked('1');
        if(n == 1)
        {
            putchar_unlocked('\n');
            continue;
        }
        if(n!=2 && !(n&1))
            prime[n] = 2;
        while(prime[n] != 0)
        {
        	putchar_unlocked(' ');
            putchar_unlocked('x');
            putchar_unlocked(' ');
            write(prime[n]);
            n /= prime[n];
            if(n!=2 && !(n&1))
                prime[n] = 2;
        }
        putchar_unlocked(' ');
        putchar_unlocked('x');
        putchar_unlocked(' ');
        write(n);
        putchar_unlocked('\n');
    }
}
