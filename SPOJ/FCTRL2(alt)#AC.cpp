#include <iostream>

using namespace std;

int main()
{
	int t,i,j,count,carry,n;
	int fact[200];
	int x;
	cin>>t;
	if(t<1 || t>100)
		return 0;	
	while(t--)
	{
		cin>>n;
		if(n>100 || n<1)
		{
			return 0;
		}
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
			while(carry>0)
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