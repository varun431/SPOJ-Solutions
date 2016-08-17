import math
from decimal import *
'''getcontext().prec = 10'''

t = int(input())
while t > 0:
	t -= 1
	n = int(input())
	sqt = math.sqrt(n) - int(math.sqrt(n))
	sqt = repr(sqt)
	'''total=sum(int(i) for i in sqt.split(''))'''
	total=0
	cnt=0
	for i in sqt:
		if i != '.':
			if cnt == 11:
				break
			cnt += 1
			total += int(i)
	print (total)
