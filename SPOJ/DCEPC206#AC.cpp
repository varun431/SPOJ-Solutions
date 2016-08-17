#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;

int SIZE;
ULL ans = 0;

void mergesort(int *a, int lbeg,int lend, int rbeg, int rend)
{
    int pa = lbeg, pb = rbeg, pt = lbeg, temp[SIZE];
    while(pa <= lend && pb <= rend)
    {
        if(a[pa] < a[pb])
        {
            temp[pt++] = a[pa];
            ans = ans + a[pa++]*(ULL)(rend-pb+1);
        }
        else
        {
            temp[pt++] = a[pb++];
        }
    }
    while(pb <= rend)
    {
        temp[pt++] = a[pb++];
    }
    while(pa <= lend)
    {
        temp[pt++] = a[pa++];
    }
    for(pt = lbeg; pt <= rend; pt++)
    {
        a[pt] = temp[pt];
    }
}

void merge(int *a, int beg, int end)
{
    if(beg < end)
    {
        int mid = (beg + end)/2;
        merge(a, beg, mid);
        merge(a, mid+1, end);
        mergesort(a, beg, mid, mid+1, end);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&SIZE);
        int *a = new int[SIZE];
        for(int i=0; i<SIZE; i++)
        {
            scanf("%d", &a[i]);
        }
        ans = 0;
        merge(a,0,SIZE-1);
        printf("%llu\n",ans);
    }
}
