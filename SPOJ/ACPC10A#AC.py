flag=1
while (flag):
	a1,a2,a3 = map(int,input().split())
	if  (a1==0 and a2==0 and a3==0):
		flag=0
		continue
	else:
		if((a2-a1)==(a3-a2)):
			diff=a2-a1
			a4=a3+diff
			print ("AP",a4)	
		else:
			ratio=a2/a1
			a4=int(a3*ratio)
			print ("GP",a4)