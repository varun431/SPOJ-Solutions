#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
#define MAX 1000010
using namespace std;

int a[MAX+10]={0};
bool prime[MAX*4];
int numPrime=37;
int p[100000];

inline void gen_primes()
{
      int i,j,c=0;
      for(i=2;i<=3*MAX;i++)prime[i]=true;
       for(i=2;i<=(int)sqrt(4*MAX);i++)
         if (prime[i])
           for(j=i;j*i < 4*MAX;j++) prime[i*j] = false;
           for(int i=1;i<sqrt(4*MAX);i++)if(prime[i])p[c++]=i;
   }

inline int sod(int n)
{
    int prod=1,k,s=0,i;
    s=n;
    for(i=0;(p[i]*p[i])<=n; i++)
    {
        int pp=1;
        while(n%p[i]==0){
            pp=pp*p[i]+1;
            n/=p[i];
        }
        prod*=pp;
    }
    if(n>1)
        prod*=1+n;
     return prod;
}

vector<int> pr;

void perfect()
{
	pr.push_back(2);
	for(int i=1;i*i<=MAX;i++)
	{
		if(prime[sod(i*i)])
		{
			pr.push_back(i*i);
		}
	}
}

 int Binary_Search(int start, int end, int val)
{
    int mid;
    while(start <= end)
    {
        if(val < pr[start]) return start-1;
        if(val > pr[end]) return end;
        mid = (start+end) / 2;
        if(val == pr[mid]) return mid;
        else if(val < pr[mid]) end = mid-1;
        else start = mid+1;
    }
    return numPrime;
}

int main()
{
    int i,j,tc,A,B;
    scanf("%d",&tc);
    gen_primes();pr.clear();
    perfect();
    while(tc--)
    {
        int count=0,count1=0;
        numPrime=37;
        scanf("%d%d",&A,&B);
        count=Binary_Search(0, numPrime-1, A-1);
        count1=Binary_Search(0,numPrime-1, B);
        printf("%d\n",count1-count);
    }
}
