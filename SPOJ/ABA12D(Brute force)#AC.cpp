#include <iostream>

using namespace std;

long long int arr[37]={2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921};
int main()
{
    long long int t,a,b,count,i;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>a>>b;
        for(i=0;i<37;i++)
        {
            if(arr[i]>=a && arr[i]<=b)
                count++;
        }
        cout<<count<<"\n";
    }
    return 0;

}