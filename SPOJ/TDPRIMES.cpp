#include <bits/stdc++.h>
#define max 100000000

using namespace std;

bool *mark;
vector<long int> prime;

void atkins()
{
    long int i,j,k=1;//int t,v;
    mark = new bool[max+1];
    mark = (bool*)memset(mark,true,max+1);
    mark[0]=mark[1]=false;
    prime.push_back(2);
    //prime.push_back(3);
    for(i=3;i*i<=max;i+=2)
    {
        if(mark[i])
        {
            for(j=i*i;j<=max;j+=2*i)
            {
                mark[j]=false;
            }
        }
    }
    for(i=3;i<max;i+=2)
    {
        if(mark[i])
            prime.push_back(i);
    }
}

int main()
{

    atkins();
    long int i,k,j,count=0;
    vector<long int>::iterator it;
    for(it=prime.begin();it!=prime.end();++it)
    {
        count++;
        //printf("%li\n",prime.back());
        if(count%100==1)
        {
            printf("%li\n",*it);
        }
    }
    //printf("%li\n",prime.size());
}
