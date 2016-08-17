#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main()
{
    long long int t,n,i,j,k;
    int a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        long long int *t1,*t2,*sortarr;
        t1 = new long long int[n];
        t2 = new long long int[n];
        sortarr = new long long int[2*n];
        for(i=1;i<=n;i++)
        {
            t1[i-1]=a*i;
            t2[i-1]=b*i;
        }
        i=j=k=0;
        while(i<n && j<n)
        {
            if(t1[i] < t2[j])
                sortarr[k++] = t1[i++];
            else if(t1[i] == t2[j])
            {
                sortarr[k++] = t1[i++];
                j++;
            }
            else
                sortarr[k++] = t2[j++];
        }
        if(i==n)
        {
            while(j<n)
                sortarr[k++] = t2[j++];
        }
        else
        {
            while(i<n)
                sortarr[k++] = t1[i++];
        }
        cout<<sortarr[n-1]<<"\n";
        delete[] t1;
        delete[] t2;
        delete[] sortarr;
    }
}
