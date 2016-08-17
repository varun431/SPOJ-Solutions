import math
l = math.log
res = []
fact = 0.0
pow = 0.0
j=1
for i in range(2,1000001):
	while 1:
		j += 1
		fact += l(j)
		pow = j*l(i)
		if fact > pow:
			res.append(j)
			break

t = int(input())
while t>0:
	t -= 1
	a = int(input())
	print (res[a-2])