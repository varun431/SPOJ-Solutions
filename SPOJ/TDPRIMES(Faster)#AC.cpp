#include <bits/stdc++.h>
#include <vector>
#define N 100000000
#define LL unsigned long long
using namespace std;

unsigned int prime[N / 64];
vector<unsigned int> p;

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
    memset( prime, -1, sizeof( prime ) );
    p.push_back(2);
    unsigned int i;
    unsigned int sqrtN = ( unsigned int )sqrt( ( double )N ) + 1;
    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
    {
        unsigned int i2 = i + i;
        for( unsigned int j = i * i; j < N; j += i2 ) rP( j );
    }
    for(i=3;i<N;i+=2)
    {
        if(gP(i))
            p.push_back(i);
    }
}

LL read()
{
    LL input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

void write(unsigned int n)
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
    putchar('\n');
}

int main()
{

    sieve();
    unsigned int count=0;
    vector<unsigned int>::iterator it;
    for(it=p.begin() ; it!=p.end() ; ++it)
    {
       count++;
       if(count%100==1)
        {
            //printf("%lu\n",*it);
            write(*it);
        }
    }
    //printf("%lu\n",p.size());
    //printf("%lu\n",p[0]);
}
