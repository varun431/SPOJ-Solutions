#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,x,y,ans;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(x&1)
            ans = 2*x-1;
        else
            ans = 2*x;
        if((x-y)==2)
            cout<<ans-2<<"\n";
        else if(x==y)
            cout<<ans<<"\n";
        else
            cout<<"No Number\n";
    }
}
