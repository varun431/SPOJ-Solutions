#include <bits/stdc++.h>
using namespace std;

inline int dfs(int *stone,int prev, int d, int x)
{
    int i=prev+1;
    int cnt = 0;
    for(; i<x; i++)
    {
        if(stone[i] == 0)
            continue;
        if(i > prev+d)
            return -1;
        if((stone[prev]+d) < stone[i])
            return -1;
        prev = i;
        cnt++;
        if(cnt == stone[0])
            break;
    }
    if((stone[prev]+d) >= x)
        return 1;
    return -1;
}

inline int dfsutil(int *stone, int first,int d, int x)
{
    if(stone[0] < (x/d-1))
        return -1;
    if(first <= d)
        return dfs(stone, first, d, x);
    return -1;
}

inline int read()
{
    int input=0;
    char c = getchar_unlocked();
    for(; c>='0' && c<='9'; c=getchar_unlocked())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

inline void write(int n)
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
    int t,i;
    t = read();
    while(t--)
    {
        int n,x,d,k=0,start=n,flag=0,temp,tmp,ans=0,first=INT_MAX;
        n = read(), x = read(), d = read();
       	int c[x] = {0};
        if(d >= x)
        {
			puts("0\n");
     		continue;
        }
        for(i=0; i<n; i++)
        {
            tmp = read();
            c[0] += tmp;
            for(int j=0; j<tmp; j++)
            {
                temp = read();
                if(first > temp)
                    first = temp;
                c[temp] = temp;
            }
            if(!flag && dfsutil(c,first,d,x) == 1)
            {
                ans = i+1;
                flag = 1;
            }
        }
        if(flag)
            write(ans);
        else{
            puts("-1");
        }
    }
}
