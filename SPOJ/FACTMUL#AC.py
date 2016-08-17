mod=int(109546051211)
n=int(input())
ans  = int(1)
f = int(1)
if n>=587117:
	print (0)
else:	
	for i in range(2,n+1):
		f = (f*i)%mod
		ans = (ans*f)%mod
	print (ans)