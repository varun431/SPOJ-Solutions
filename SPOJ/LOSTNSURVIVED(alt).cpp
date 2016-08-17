#include <bits/stdc++.h>
#define limit 100007
#define pb push_back
#define sf scanf
#define pf printf
#define ll long long
#define REP(i,a,b) for(int i = int(a); i < int(b); i++)
using namespace std;

vector<int> pset(limit);
vector<int> member(limit,1);

inline ll read()
{
    ll input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

inline void write(ll n)
{
    char out[32],i=0;
    if(n==0)
        putchar('0');
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

void initset(int size)
{
    pset.resize(size);
    member.resize(size);
    REP(i,0,size)
        pset[i] = i, member[i] = 1;
}

int findset(int i)
{
    return (pset[i] == i) ? i : (pset[i] = findset(pset[i]));
}

void unionset(int i, int j)
{
    int findi = findset(i), findj = findset(j);
    pset[findi] = findj;
    member[findj] += member[findi];
    //cout<<pset[j]<<" Value of pset[j]\n"<<pset[i]<<" Value of pset[i]\n"<<member[pset[j]]<<" Member\n";
}

bool issameset(int i, int j)
{
    return (pset[i] == pset[j]);
}

int diffset(int size)
{
    int max = INT_MIN, min = INT_MAX;
    REP(i,0,size)
    {
        if(pset[i] == i)
        {
            //cout<<i<<" Value of i\n"<<member[i]<<" Member\n";
            if(member[i] > max)
                max = member[i];
            if(member[i] < min)
                min = member[i];
        }
    }
    cout<<max<<" -MAX "<<min<<" -MIN\n";
    return max-min;
}

int main()
{
    int n,q;
    n = read(), q = read();
    initset(n);
    while(q--)
    {
        int a, b;
        a = read(), b = read();
        a -= 1, b -= 1;
        if(!issameset(a,b))
            unionset(a,b);
        write(diffset(n));
    }
}
