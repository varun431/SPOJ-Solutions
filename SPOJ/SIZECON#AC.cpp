#include <bits/stdc++.h>
int main()
{
    int t,i,s=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&i);
        if(i>0)
            s+=i;
    }
    printf("%d",s);
}
