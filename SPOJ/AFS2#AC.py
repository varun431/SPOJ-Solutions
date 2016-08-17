def sum(a,b):
	n = b-a+1
	value = n*(a+b)
	return int(value/2)

t = int(input())
while(t>0):
	t=t-1
	n = int(input())
	ans = int(0)
	sqt = int(n**0.5)
	for i in range(1,sqt+1):
		a = int(n/i)
		b = int(n/(i+1)+1)
		value = sum(b,a)
		ans += ((i-1)*value) + (i*(a-1))
	if (i*(i+1)) > n:
		ans -= i*(a-1)
	print (int(ans))