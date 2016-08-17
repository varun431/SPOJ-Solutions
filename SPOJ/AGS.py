t =int(input())
while t>0:
	t -= 1
	a,d,r = input().split()
	a,d,r = int(a),int(d),int(r)
	n,mod = input().split()
	n,mod = int(n),int(mod)
	if r==1:
		n >>= 1
		ans = a + n*d
	else:	
		if n&1:
			n >>= 1
			po = r**n
			ans = a*po + (r*d*(po-1)/(r-1))
		else:
			n = (n-1) >> 1
			po = r**n
			ans = a*po + (r*d*(po-1)/(r-1)) + d
	ans = int(ans)	
	if ans < 0:
		ans += mod
	if ans >= mod:
		print (ans%mod)
	else:
		print (ans)	  	