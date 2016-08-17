#include <bits/stdc++.h>

int main()
{
    long int t,n,i;
    scanf("%li",&t);
    while(t--)
    {
        long count=0;
        scanf("%li",&n);
        for(i=5;n/i>0;i*=5)
        {
            count+=n/i;
        }
        printf("%li\n",count);
    }
}
