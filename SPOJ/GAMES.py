import math
t = int(input())
while t>0:
	avg = float(input())
	avg = float("{0:.4f}".format(avg))
	no = avg - math.floor(avg)
	if no == 0:
		print (1)
	else:	
		#print ("HI")
		res = 1.0000/no
		res = float("{0:.4f}".format(res))
		#print (res)
		ans = math.ceil(res) - res
		if ans < 0.0001:
			print (math.floor(res))
		else:
			print (math.ceil(res))	
	t = t - 1
