#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        for(int i=x; i<n; i+=x)
        {
            if(i%x == 0 && i%y != 0)
                cout<<i<<" ";
        }
        cout<<endl;
    }
}
