#include <bits/stdc++.h>
using namespace std;

bool isPrefix(string a, string b)
{
    for(int i=0; i<a.size(); i++)
        if(a[i] != b[i])
            return false;
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string no[n];
        for(int i=0; i<n; i++)
            cin>>no[i];
        sort(no,no+n);
        for(int i=0; i<n-1; i++)
        {
            if(no[i].size()<=no[i+1].size() && isPrefix(no[i],no[i+1]))
            {
                cout<<"NO\n";
                goto last;
            }
        }
        cout<<"YES\n";
last:   int y=1;
    }
}
