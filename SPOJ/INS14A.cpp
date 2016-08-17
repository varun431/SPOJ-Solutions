#include <bits/stdc++.h>
#define U unsigned int
using namespace std;

U steps(char n[], U m)
{
    U i,j,len;
    len = strlen(n);
    if(len&1)
    {
        i = j = len/2;
        while(i >= 0 || j < len)
        {
            if(n[i]=='1' || n[j]=='1')

        }
    }
}

int main()
{
    U t;
    scanf("%u",&t);
    while(t--)
    {
        U m;
        scanf("%u",m);
        char n[50000];
        scanf("%s",n);
        for(int i=0; i<strlen(n); i++)
        {
            if(n[i] == '1')
            {

            }
        }
        printf("%u\n",steps(n,m));
    }
}
