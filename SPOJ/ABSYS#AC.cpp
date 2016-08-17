#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <stdlib.h>

int main()
{
    int t;
    long c1,c2,c3;
    char v1[50],v2[50],v3[50];
    char st[] = "machula";
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s + %s = %s",v1,v2,v3);
        if(strstr(v1,st)!=NULL)
        {
            c2 = strtol(v2,NULL,10);
            c3 = strtol(v3,NULL,10);
            c1 = c3-c2;
        }
        else if(strstr(v2,st)!=NULL)
        {
            c1 = strtol(v1,NULL,10);
            c3 = strtol(v3,NULL,10);
            c2 = c3-c1;
        }
        else
        {
            c1 = strtol(v1,NULL,10);
            c2 = strtol(v2,NULL,10);
            c3 = c1+c2;
        }
        printf("%ld + %ld = %ld\n",c1,c2,c3);
    }
}
