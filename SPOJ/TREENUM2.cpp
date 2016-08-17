#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define power(x) pow(3,x)
#define max 100000000

using namespace std;

long long int *treenum;

void treenumf()
{
    long long int i,j,n,count=0,sum;
    treenum = new long long int[max];
    for(i=1;i<=max;i++)
    {
        n=0,sum=0;
        while(i>power(n))
        {
            n++;
        }
        if(i==power(n))
        {
            treenum[count++]=i;
            continue;
        }
        sum+=power(n-1);
        for(j=n-2;j>=0;j--)
        {
            sum+=power(j);
            if(sum==i)
            {
                treenum[count++]=i;
                break;
            }
            if(sum<i)
            {
                continue;
            }
            else
            {
                sum-=power(j);
                continue;
            }
        }
    }
}

int main()
{
    treenumf();
    int t;
    long long int l,r,i,sum,p;
    p = (long long int)pow(2,32);
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>l>>r;
        for(i=l;i<=r;i++)
        {
            //cout<<treenum[i-1]<<"\n";
            sum=(sum+treenum[i-1])%p;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
