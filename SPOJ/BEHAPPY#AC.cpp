#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,x,y;
int a[26],b[26];
int cnt[26][2506];

int sol(int i,int rem)
{
    if(cnt[i][rem] != -1)return cnt[i][rem];
    if(i == m)
    {
        if(rem == 0)return 1;
        return 0;
    }
    int x=0;
    for(int j=a[i] ; j<=b[i] and j<=rem ; j++)
        x += sol(i+1,rem-j);
    return cnt[i][rem]=x;
}

int main()
{
    memset(cnt,-1,sizeof cnt);
    cin >> m >> n;
    int i=0 ;
    while(1)
    {
        cin >> x >> y;
        if(x == 0 and y == 0)break;
        a[i] = x;
        b[i] = y;
        i++;
    }
    sol(0,n);
    cout << cnt[0][n] << "\n";
}
