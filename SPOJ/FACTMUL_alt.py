import math
from decimal import *
getcontext().prec = 100
mod=int(109546051211)

def power(x,n):
	res=1
	while n>0:
		if n%2==1:
			res=(res*x)%mod
		x=(x*x)%mod
		n >>= 1
	return res%mod	

n=int(input())
ans  = int(1)
f = int(0)

if n>=587117:
	print (0)
else:	
	for i in range(1,n+1):
		value = Decimal(i)
		l = value.log10()
		f = (f + ((n-i+1)*l)%mod)%mod
	print ("{}   {}".format(value,l))	
	print (math.floor(10**f)%mod)