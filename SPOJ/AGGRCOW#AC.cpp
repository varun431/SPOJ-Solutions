#include <bits/stdc++.h>
using namespace std;
int n,c;
int cow(int mid, int arr[])
{
    int cows=1, pos=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]-pos >= mid)
        {
            pos = arr[i];
            cows++;
            if(cows == c)
                return 1;
        }
    }
    return 0;
}

int search(int arr[])
{
    int ini=0, last=arr[n-1], max=-1;
    while(last > ini)
    {
        int mid = (ini+last)/2;
        if(cow(mid, arr) == 1)
        {
            max = mid;
            ini = mid+1;
        }
        else
            last = mid;
    }
    return max;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &c);
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr,arr+n);
        int large = search(arr);
        printf("%d\n", large);
    }
}
