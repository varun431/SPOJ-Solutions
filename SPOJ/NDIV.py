a,b,n = map(int,input().split())
cnt=0;
for i in range (a,b+1):
	num=i
	ndiv=1k
	count=0;
	while num%2==0:
		count+=1
		num=num/2
	ndiv=ndiv*(1+count)	
	for j in range (3,int(num**0.5)+1,2):
		count=0
		while num%j==0:
			count+=1
			num=num/j
		ndiv=ndiv*(1+count)	
	if(num>2):
		ndiv=ndiv*2	
	if (ndiv==n):
		cnt+=1
print (cnt)		
