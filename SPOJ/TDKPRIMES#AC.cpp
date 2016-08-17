#include <bits/stdc++.h>
#define N 100000000
using namespace std;

long int prime[N / 64];
vector<long int> p;

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
    memset( prime, -1, sizeof( prime ) );
    p.push_back(2);
    long int i;
    long int sqrtN = ( long int )sqrt( ( double )N ) + 1;
    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
    {
        long int i2 = i + i;
        for( long int j = i * i; j < N; j += i2 ) rP( j );
    }
    for(i=3;i<N;i+=2)
    {
        if(gP(i))
            p.push_back(i);
    }
}

int main()
{

    sieve();
    int q;
    long int k;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%li",&k);
        printf("%li\n",p[k-1]);
    }
    //printf("%lu\n",p.size());
    //printf("%lu\n",p[0]);
}
