import math
from decimal import Decimal, getcontext
getcontext().prec = 1005
t = int(input())
while t > 0:
	t -= 1
	n = int(input())
	sqt = Decimal(n).sqrt()
	sqt = sqt - int(sqt)
	sqt = str(sqt)
	sum=0
	cnt=0
	if sqt==0:
		print (0)
	else:	
		for i in sqt:		
			if cnt>1:
				if cnt==1002:
					break
				sum += int(i)
				cnt+=1
			else:
				cnt+=1	

		print (sum)
