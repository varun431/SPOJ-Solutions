#include <bits/stdc++.h>

 int main()
 {
     int t;
     scanf("%d",&t);
     while(t--)
     {
         long int w,b;
         scanf("%li %li",&w,&b);
         float prob = 0;
         if(int(b)&1)
         {
             prob = 1;
         }
         printf("%.6f\n",prob);
     }
 }
