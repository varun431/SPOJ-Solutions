mark = [0]*1000001
def prime():
	mark[0]=mark[1]=mark[2]=1
	for i in range (2,1001):
		for j in range(i*i,1000001,i):
			if mark[j]==0:
				mark[j]=1

import math
prime()
t = int(input())
while (t>0):
	count=0
	a,b = map(int, input().split())
	for i in range (a,b+1):
	    sum=1
	    num=i
	    cnt=0
	    while num%2==0:
	    	cnt=cnt+1
	    	num=num/2
	    sum=sum*(math.pow(2,cnt+1)-1)
	    for j in range(3,int(math.sqrt(num)+1)):
	    	cnt=0
	    	while num%j==0:
	    		cnt=cnt+1
	    		num=num/j
	    	sum=sum*(math.pow(j,cnt+1)-1)/(j-1)
	    if num>2:
	    	sum=sum*(num+1)	
	    if mark[int(sum)] == 0:
	    	count=count+1
	print (str(count))
	t-=1