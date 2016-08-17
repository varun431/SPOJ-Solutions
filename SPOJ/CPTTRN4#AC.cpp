#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,c,h,w,firstast;
        scanf("%d %d %d %d",&l,&c,&h,&w);
        firstast = c*(w+1)+1;
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<firstast; j++)
                cout<<"*";
            cout<<endl;
            int astcnt=0;
            for(int z=0; z<h; z++)
            {
                cout<<"*";
                for(int j=1; j<firstast; j++)
                {
                    if(astcnt==w)
                    {
                        cout<<"*";
                        astcnt = 0;
                        continue;
                    }
                    cout<<".";
                    astcnt++;
                }
                cout<<endl;
            }
        }
        for(int j=0; j<firstast; j++)
            cout<<"*";
        cout<<"\n\n";
    }
}
