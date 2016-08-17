t = int(input())
mod = 1298074214633706835075030044377087
while t>0:
	t = t - 1
	n = int(input())
	pow = 2**(n+1)
	print ((pow-1)%mod)