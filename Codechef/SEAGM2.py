from decimal import *
getcontext.prec=6
t = int(raw_input())
for te in range(t):
	n,m = map(int,raw_input().split(' '))
	su=0
	for i in range(n):
		mu=Decimal(1.0)
		s = raw_input()
		a = map(float,s.split(' '))
		
		for j in range (m):
			bc = Decimal(a[j])
			mu = Decimal(mu*bc)
			if(i==0):
				b=mu
		su = Decimal(su + mu)
	if(su!=0):
		answ = Decimal(b/su)
		print answ
	else:
		print ("0.000000")
