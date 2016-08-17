#include <bits/stdc++.h>
using namespace std;

double find_area(int x,int y,int z)
{
    double p = ((x+y+z)*1.0)/2.0;
    double a = sqrt(p*(p-x)*(p-y)*(p-z));
    return a;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int l[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&l[i]);
        }
        sort(l,l+n);
        double area[20];
        area[n]=0.0;
        for(int i=n-1; i>=0; i--)
        {
            int j=i+1,k=j+1;
            area[i] = area[i+1];
            while(k<n)
            {
                if((l[i] + l[j]) > l[k])
                {
                    for(int m=j; m<k; m++)
                        area[i] = max(area[i], find_area(l[i],l[j],l[k])+area[k+1]);
                    k++;
                }
                else
                    j++;
            }
        }
        printf("%.6lf\n",area[0]);
    }
}
