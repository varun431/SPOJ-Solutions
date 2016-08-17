from decimal import *
getcontext().prec = 19
t = int(input())
for ts in range(0,t):
	p,n = input().split()
	p,n = int(p),int(n)
	ans = 0
	power = p
	while int(n/power) > 0:
		rem = n%power + 1
		div = int(Decimal(n)//Decimal(power))
		ans += rem*div + (power*(div-1)*div >> 1)
		power = power * p
	print (ans)