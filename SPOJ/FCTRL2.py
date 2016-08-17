t = int(input())
while(t>0):
	t=t-1
	n = int(input())
	result = 1
	for i in range (1,n+1):
		result = result * i
	print (result)