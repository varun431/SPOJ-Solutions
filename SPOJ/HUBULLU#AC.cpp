#include<stdio.h>
int main()
{
 int i,j,n,m;
 scanf("%d",&n);
 for(m=0;m<n;m++)
 {
  scanf("%d%d",&i,&j);
  if(j==0)
  {
   printf("Airborne wins.\n");
  }
  if(j==1)
  {
   printf("Pagfloyd wins.\n");
  }
 }
 return 0;
}
