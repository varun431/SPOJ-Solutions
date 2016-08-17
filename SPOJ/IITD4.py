from decimal import *
getcontext().prec = 50 
t = int(input())
mod = 1000000007

def power(base,n):
	res=1
	while n>0:
		if n%2==1:
			res = (res*base)%mod
		base = (base*base)%mod
		n>>=1
	return res%mod
	
while t>0:
	t -= 1
	a,b,k = map(int,input().split())
	sum = 0
	for i in range(1,b+1):
		mul = int(b/i) - int((a-1)/i)
		sum = (sum + (mul*power(i,k))%mod)%mod
	print (int(sum))