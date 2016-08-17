#include <bits/stdc++.h>
#define ll long long
#define loop(i,s,n) for(int i=s; i<n; i++)
#define List list<ll>
#define Map map<ll,List* >
#define Pair pair <ll,ll>
#define mp make_pair
#define pb push_back
using namespace std;

class dll
{
    ll data;
    dll* rlink;
    dll* llink;
};

ll tri1(Map x, Map y,ll X,ll Y)
{
    ll counter1=1,counter2=1,ans=0;
    Map::iterator it1,it2;
    it1 = x.find(X), it2 = y.find(Y);
    for(++it1,++it2; counter2<x[X] && counter1<y[Y];)
    {
        if((it1->first - X) == (it2->first - Y))
        {
            ans++;
            it1++, it2++, counter1++,counter2++;
            continue;
        }
        ((it1->first - X) < (it2->first - Y))? (it1++,counter1++): (it2++,counter2++);
    }
    //cout<<ans<<" tri1\n";
    return ans;
}

ll tri2(Map x, Map y,ll X,ll Y)
{
    ll counter1=1,counter2=1,ans=0;
    Map::iterator it1,it2;
    it1 = x.find(X), it2 = y.find(Y);
    for(--it1,++it2; counter2<x[X] && counter1<y[Y];)
    {
        if((X - it1->first) == (it2->first - Y))
        {
            ans++;
            it1--, it2++, counter1++,counter2++;
            continue;
        }
        ((X - it1->first) < (it2->first - Y))? (it1--,counter1++): (it2++,counter2++);
    }
    //cout<<ans<<" tri2\n";
    return ans;
}

ll tri3(Map x, Map y,ll X,ll Y)
{
    ll counter1=1,counter2=1,ans=0;
    //cout<<x[1223]<<" Test\n";
    Map::iterator it1,it2;
    it1 = x.find(X), it2 = y.find(Y);
    for(--it1,--it2; counter2<x[X] && counter1<y[Y] && it1->first>=x.begin()->first && it1->first<=(x.end()-1)->first && it2->first>=y.begin()->first && it2->first<=(y.end()-1)->first;)
    {
        /*if(X != it1->first && Y != it2->second)
        {
            break;
        }*/
        cout<<(x.end())->first<<" values\n";
        if((X - it1->first) == (Y - it2->first))
        {
            ans++;
            it1--, it2--, counter1++,counter2++;
            continue;
        }
        ((X - it1->first) < (Y - it2->first))? (it1--,counter1++): (it2--,counter2++);
    }
    //cout<<ans<<" tri3\n";
    return ans;
}

ll tri4(Map x, Map y,ll X,ll Y)
{
    ll counter1=1,counter2=1,ans=0;
    Map::iterator it1,it2;
    it1 = x.find(X), it2 = y.find(Y);
    for(++it1,--it2; counter2<x[X] && counter1<y[Y];)
    {
        if((it1->first - X) == (Y - it2->first))
        {
            ans++;
            it1++, it2--, counter1++,counter2++;
            continue;
        }
        ((it1->first - X) < (Y - it2->first))? (it1++,counter1++): (it2--,counter2++);
    }
    //cout<<ans<<" tri4\n";
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    Map x,y;
    ll pt[n][2];
    //vector <Pair> *pt;
    ll input1,input2,ans=0,X,Y;
    loop(i,0,n)
    {
        scanf("%lli %lli",&input1,&input2);
        //x[input1]++, y[input2]++;
        x[input1] =
        pt[i][0] = input1, pt[i][1] = input2;
        //pt.pb(mp(input1,input2));
    }
    loop(i,0,n)
    {
        X = pt[i][0], Y = pt[i][1];
        ans += tri1(x,y,X,Y);
        ans += tri2(x,y,X,Y);
        ans += tri3(x,y,X,Y);
        ans += tri4(x,y,X,Y);
    }
    printf("%lli\n",ans);
}
