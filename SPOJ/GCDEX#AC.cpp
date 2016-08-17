#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1000001;
int phi[N];
ll res[N],cum[N];
void solve()
{
    for(int i=1;i<N;i++) phi[i]=i;
    for(int i=2;i<N;i++){
        if(phi[i]==i){
            for(int j=i;j<N;j+=i){
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            res[j]=res[j]+1ll*i*phi[j/i];
        }
    }
    for(int i=1;i<N;i++) res[i]-=i;
    cum[0]=0;
    for(int i=1;i<N;i++){
        cum[i]=cum[i-1]+res[i];
    }
}

int read()
{
    int input=0;
    char c = getchar_unlocked();
    if(c == '\0')
    	return 0;
    for(; c>='0' && c<='9'; c=getchar_unlocked())
    {
    	if(c == '\0')
    		return 0;
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

void write(ll n)
{
    char out[32],i=0;
    while(n!=0)
    {
        out[i++] = n%10 + '0';
        n /= 10;
    }
    while(i!=0)
    {
        putchar_unlocked(out[--i]);
    }
    putchar_unlocked('\n');
}

int main()
{
    solve();
    int n;
    //n = read();
    while(scanf("%d",&n) != EOF){
        if(n==0)
            return 0;
        //printf("%lld\n",cum[n]);
        write(cum[n]);
        //n = read();
    }
    return 0;
}
