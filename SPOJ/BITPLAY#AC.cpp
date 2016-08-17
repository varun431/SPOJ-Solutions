#include <bits/stdc++.h>
using namespace std;

int no_of_ones(unsigned int n){
	int c=0;
	while(n!=0){
		if(n%2!=0)
			c++;
		n = n>>1;
	}
	return(c);
}
int eliminate_ones(int n,int k){
	int i=1,bit;
	for(;i<32;i++){
		bit = (n >> i) & 1;
		if(bit){
			n &= ~(1 << i);
			k--;
			if(k==0)
				break;
		}
	}
	return(n);
}
int main(void) {
	int n,k,oc,t;
	scanf("%d",&t);
	while(t--) {
        scanf("%d %d\n",&n,&k);
        if(k==0){
            printf("-1\n");
            t--;
            continue;
        }
        if(k==1){
            printf("1\n");
            t--;
            continue;
        }
        if(n%2==0)
            n--;
        else
            n = n-2;
        oc = no_of_ones(n);
        if(oc<=k)
            printf("%d\n",n);
        else {
            printf("%d\n",eliminate_ones(n,oc-k));
        }
	}
}

