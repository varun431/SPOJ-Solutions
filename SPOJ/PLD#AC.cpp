#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,i,j,l,count=0;
    scanf("%d",&k);
    char str[30000];
    scanf("%s",str);
    for(l=0;l<=strlen(str)-k;l++)
    {
        j = k+l;
        i = -1+l;
        int flag=1;
        while(++i <= --j)
        {
            if(str[i]!=str[j])
            {
                flag=0;
                break;
            }
        }
        if(flag)
            count++;
    }
    printf("%d\n",count);
}
