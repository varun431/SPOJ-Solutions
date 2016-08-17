t=int(input())
while t:
 n=int(input())
 if n%2==0:
  k=n*n
  if k%48>24:
   result= k/48  + 1
  else:
   result= k/48
 else:
  k=(n+3)*(n+3)
  if k%48>24:
   result= k/48 + 1
  else:
   result= k/48
 print (int(result))
 t=t-1