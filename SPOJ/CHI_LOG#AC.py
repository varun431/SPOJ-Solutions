from decimal import *
t = int(input())
while t>0:
	t -= 1
	x = Decimal(input())
	ans = x.ln(Context(prec=100))
	ans = str(ans)
	s = ''
	count = 0
	for i in ans:
		count += 1
		if i == '.':
			break;
		s += i
	s += ans[count:]
	print (s)