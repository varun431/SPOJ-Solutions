import math
from decimal import *
getcontext().prec = 100					

def compute(n,p):
	if p==1:
		return Decimal(n**2 + n)/Decimal(2)
	elif p==2:
		return Decimal(2*n**3 + 3*n**2 + n)/Decimal(6)
	elif p==3:
		return Decimal(n**4 + 2*n**3 + n**2)/Decimal(4)
	elif p==4:
		return Decimal(6*n**5 + 15*n**4 + 10*n**3 - n)/Decimal(30)
	elif p==5:
		return Decimal(2*n**6 + 6*n**5 + 5*n**4 - n**2)/Decimal(12)
	elif p==6:
		return Decimal(6*n**7 + 21*n**6 + 21*n**5 - 7*n**3 + n)/Decimal(42)
	elif p==7:
		return Decimal(3*n**8 + 12*n**7 + 14*n**6 - 7*n**4 + 2*n**2)/Decimal(24)
	elif p==8:	
		return Decimal(10*n**9 + 45*n**8 + 60*n**7 - 42*n**5 + 20*n**3 - 3*n)/Decimal(90)
	elif p==9:
		return Decimal(2*n**10 + 10*n**9 + 15*n**8 - 14*n**6 + 10*n**4 - 3*n**2)/Decimal(20)
	elif p==10:
		return Decimal(6*n**11 + 33*n**10 + 55*n**9 - 66*n**7 + 66*n**5 - 33*n**3 + 5*n)/Decimal(66)

def sum(a,b,k):
	sumo = compute(b,k) - compute(a-1,k)
	return sumo

t = int(input())
while t>0:
	t = t-1
	n,k,m = map(int,input().split())
	ans = int(0)
	sqt = int(n**0.5)
	for i in range(1,sqt+1):
		b = int(n/i)
		a = int(n/(i+1))+1
		value = sum(a,b,k)
		ik = i**k
		ans += (i*value + ik*b)
	if (i*(i+1)) > n:
		ans -= ik*b	
	if ans >= m:	
		print (int(ans%m))
	else:	
		print (int(ans))

# ans 607680694
#36953702

#2
#100000 8 1000000007
#100 10 1000000007