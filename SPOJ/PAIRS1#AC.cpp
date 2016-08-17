#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
    int n,k,temp,ans=0;

    map<long long,int> arr;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&temp);
        arr[temp] = 1;
    }
    for(auto it=arr.begin(); it!=arr.end(); it++)
    {
        if((it->first - k)>=0 && arr[it->first - k]!=0)
            ans++;
    }
    printf("%d\n", ans);
}
