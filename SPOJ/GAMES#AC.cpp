#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
     int t,count,i,temp;
     scanf("%d",&t);
     while(t--)
     {
          string s;
          cin>>s;
          long number=0,frac;
          count=0;
          temp=0;
          for(i=s.size()-1;i>=0;i--)
          {
               if(s[i]=='.')
               {
                    temp=1;
                    break;
               }
               else
                    count++;
          }
          for(i=0;i<s.size();i++)
          {
               if(s[i]!='.')
               {
                    number=number*10 + (s[i]-48);
               }
          }
          frac=1;
          if(temp)
                frac=pow(10,count);
          printf("%ld\n",frac/__gcd(number,frac));
     }
     return 0;
}
