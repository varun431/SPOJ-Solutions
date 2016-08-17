#include <bits/stdc++.h>
int main()
{
    int T,n,i,m,d,cnt=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&d);
        int h[n];
        cnt=0;

        for(i=0;i<n;i++)
        {
                scanf("%d",&h[i]);
                cnt += (h[i]/d);
        }
        if(cnt>=m)
        	printf("YES\n");
        else
        	printf("NO\n");
    }
}
