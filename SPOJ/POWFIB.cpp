#include <bits/stdc++.h>
#define ul long long
#define MAX 90000000
#define mod 1000000007
#define loop(i,n) for(int i=0; i<n; i++)
#define loopinc(i,n) for(int i=1; i<=MAX; i++)
using namespace std;

typedef vector<vector<ul> > matrix;
const long long k=2;

inline ul mulmod(ul a, ul b)
{
    int x=0,y=a%mod;
    while(b>0)
    {
        if(b&1)
            x = (x+y)%mod;
        y = (y+y)%mod;
        b>>=1;
    }
    return x%mod;
}

inline matrix mul(matrix a, matrix b)
{
    matrix T(k, vector<ul>(k));
    loop(i,k) loop(j,k) loop(z,k)
    {
        T[i][j] = (T[i][j] + mulmod(a[i][z],b[z][j])) % mod;
    }
    return T;
}

inline matrix pow(matrix a, ul p)
{
    matrix ans(k,vector<ul>(k));
    ans[0][0] = 1, ans[0][1] = 0, ans[1][0] = 0, ans[1][1] = 1;
    if(p==1)
        return a;
    while(p>0)
    {
        if(p&1)
        {
            ans = mul(ans,a);
        }
        a = mul(a,a);
        p>>=1;
    }
    return ans;
}

inline ul fib(ul n)
{
    ul ans=0;
    matrix R(k,vector<ul>(k));
    R[0][0] = 0, R[0][1] = 1, R[1][0] = 1, R[1][1] = 1;
    if(n==1)
        return 1;
    R = pow(R, n-1);
    loop(i,k)
        ans = (ans + R[0][i]) % mod;
    return ans;
}

inline ul non_fib(ul n)
{
    ul a=1,b=2,c=3;
    while( n > 0 )
    {
        a=b;
        b=c;
        c=a+b;
        n -= (c-b-1);
    }
    n+=(c-b-1);
    return (b+n);
}

inline ul power(ul base,ul p)
{
    ul ans=1;
    while(p>0)
    {
        if(p&1)
            ans = mulmod(ans,base);
        base = mulmod(base,base);
        p>>=1;
    }
    return ans%mod;
}

inline ul result(ul fibo,ul nonfibo)
{
    return power(nonfibo,fibo);
}

/*inline void cal()
{
    loopinc(i,MAX)
    {
        fibo.push_back(fib(i));
        nfibo.push_back(non_fib(i));
    }
}*/

int main()
{
    ul *anfibo = new ul[MAX], *afibo = new ul[MAX];
    ul t;
    scanf("%lli",&t);
    while(t--)
    {
        ul n,ans;
        scanf("%lli",&n);
        if(afibo[n]==0)
        {
            afibo[n] = fib(n);
        }
        if(anfibo[n]==0)
        {
            anfibo[n] = non_fib(n);
        }
        ans = result(afibo[n], anfibo[n]);
        printf("%lli\n",ans);
    }
}
