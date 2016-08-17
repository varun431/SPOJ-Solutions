#include <iostream>

using namespace std;

int main()
{
	int t,i,n,z,j,count,carry;
	int fact[10000];
	int x;
	cin>>t;
	if(t<1 || t>100)
		return 0;
	for(z=0;z<t;z++)
	{
		cin>>n;
		carry=0;
		count=1;
		fact[0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<count;j++)
			{
				x=fact[j]*i+carry;
				carry=x/10;
				fact[j]=x%10;
			}
			while(carry!=0)
			{
				fact[count++]=carry%10;
				carry=carry/10;
			}
		}
		cout<<"\n";
		for(i=count-1;i>=0;i--)
		{
			cout<<fact[i];
			fact[i]=0;
		}
	}
	return 0;
}
