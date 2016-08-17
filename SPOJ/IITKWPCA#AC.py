def check(n):
	a=n.split(' ')
	x = list(set(a))
	try:
		x.remove('')
	except ValueError:
		t=1	
	l=len(x)
	print (l)

t = int(input())
while t>0:
	t-=1
	n=raw_input()
	check(n)