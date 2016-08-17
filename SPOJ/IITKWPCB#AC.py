import math
t = int(input())

def euclid(a,b):
	r = a%b
	if r==0:
		return b	
	return euclid(b,r)

while(t>0):
	t = t-1
	n = int(input())
	b = math.floor(n/2)
	if b == 0:
		print (n)
		continue
	elif n == 0:
		print (b)
		continue	
	for i in range (b,0,-1):
		gcd = euclid(n,i)
		if gcd == 1:
			print (i)
			break




