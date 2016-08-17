#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[2000];
    int t=0;
    while(1)
    {
        stack<char> stk;
        int open=0, cnt=0;
        t++;
        cin>>s;
        if(s[0] == '-')
            break;
        for(int i=0; i<strlen(s); i++)
        {
            if(s[i] =='{')
                open++;
            else if(s[i] == '}' and open==0)
            {
                open++;
                cnt++;
            }
            else
                open--;
        }
        cout<<t<<". "<<open/2 + cnt<<endl;
    }
}
