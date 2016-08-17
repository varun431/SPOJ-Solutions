#include <string.h>
#include <iostream>
#define ll long long
using namespace std;

int po(int base, int exp)
{
    int ans=1;
    for(int i=0; i<exp; i++)
        ans*=base;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll b,res;
        char a[1000];
        cin>>a;
        cin>>b;
        int l=strlen(a), c=a[l-1]-'0';
        if(c==0)
            cout<<"0"<<endl;
        else
        {
            b=b%4;
            res=po(c,b);
            cout<<res%10<<endl;
        }
    }
}
