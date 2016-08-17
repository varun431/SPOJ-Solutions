    #include<cstring>
    #include<string>
    #include<cstdio>
    #include<cstdlib>
    #include<iostream>
    #include<cmath>
    #include<vector>
    #include<algorithm>
    #include<queue>
    using namespace std;
    #define ll long long
    #define pf printf
    #define sf scanf
    #define Fill(a,b) memset(a,b,sizeof(a))
    const int N = 100000;
    bool v[N + 10];
    ll s[N + 10],t[N + 10];
    int p[N + 10];
    int tot,n;
    int x;
    int sum[N + 10];
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

	inline void write(ll n)
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
    void get_prime()
    {
        Fill(v,0);
        tot = 0;
        for (int i = 2; i <= N; i++)
            if (!v[i])
            {
                p[++tot] = i;
                for (int j = i * 2; j <= N; j += i) v[j] = 1;
            }
    }
    inline int solve(int x,int y)
    {
       /* ll sum = 0;ll tp = n;
        while (tp > 0ll)
        {
            sum = sum + tp / x;
            tp = tp / x;
        }
        return sum / y;*/
        return sum[x] / y;
    }
    inline int get(int x)
    {
        int sum = 0;
        int tp = n;
        while (tp > 0)
        {
            sum = sum + tp / x;
            tp = tp / x;
        }
        return sum;
    }
    int main()
    {
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","r",stdout);
        get_prime(); //cout<<tot<<endl;
        int cas = 0;
        while (1)
        {
        	n=read(),x=read();
            //cas++; pf("%d\n",cas);
            for (int i = 2; i <= n; i++) sum[i] = get(i);
            if (n == 0 && x == 0) break;
            ll ans = 0;
            while(1)
            {
                int lim = tot;
                for (int i = 1; i <= tot; i++)
                {
                    s[i] = solve(p[i],x);
                    t[i] = solve(p[i],x + 1);
                    if (s[i] == 0)
                    {
                        lim = i - 1;
                        break;
                    }
                }
                if (lim == 0) break;
                //break;
                ll tmp1 = 1,tmp2 = 1;
                for (int i = 1; i <= lim; i++) tmp1 = tmp1 * (s[i] + 1),tmp2 = tmp2 * (t[i] + 1);
               // for (int i = 1; i <= lim; i++) cout<<s[i]<<endl;
                tmp1 = tmp1 - tmp2;
                ans = ans + (tmp1 * (tmp1 - 1)) / 2;
                x++;
            }
            pf("%lld\n",ans);
            //write((ll)ans);
        }
        return 0;
    }
