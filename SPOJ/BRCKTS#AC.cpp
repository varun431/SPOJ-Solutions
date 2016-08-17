#include <bits/stdc++.h>

int main()
{
    int t=10;
    int nbrac,nop;
    while(t--)
    {
        int count=0,i,j,z;
        scanf("%d",&nbrac);
        char *brac = new char[nbrac];
        scanf("%s",brac);
        scanf("%d",&nop);
        int *op = new int[nop];
        int *res = new int[nop];
        for(i=0;i<nop;i++)
        {
            int ans=0;
            scanf("%d",&op[i]);
            if(op[i]>0)
            {
                if(brac[op[i]-1]=='(')
                    brac[op[i]-1] = ')';
                else
                    brac[op[i]-1] = '(';
                //printf("%s\n",brac);
            }
            else
            {
                for(j=0;j<nbrac;j++)
                {

                    if(brac[j]=='(')
                        ans+=1;
                    else
                        ans+=-1;
                    if(ans<0)
                        break;
                }
                if(ans==0)
                {
                    res[count++] = 1;
                }
                else
                {
                    res[count++] = 0;
                }
            }
        }
        for(z=0;z<count;z++)
        {
            if(res[z])
                printf("YES\n");
            else if(!res[z])
                printf("NO\n");
        }
        delete[] res,op,brac;
    }
}
