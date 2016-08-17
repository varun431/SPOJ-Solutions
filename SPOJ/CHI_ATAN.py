from decimal import *
import math
import numpy
getcontext().prec = 200
t = int(input())
while t>0:
	t -= 1
	x = Decimal(input())
	ans = numpy.arctan(x)
	#ans = Decimal(math.atan(Decimal(x)))
	ans = str(ans)
	s = ''
	count = 0
	for i in ans:
		count += 1
		if i == '.':
			break;
		s += i
	s += ans[count:]
	if s != '0' and s[0] == '0':
		s = s[1:]
	print (s)