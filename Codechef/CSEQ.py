M = 1000003
F=[1]*1000004

def Factorial(n):
	a=1
	for i in range(1,n):
		a=a*i
	return a*n

def init():
	for i in range(1,M):
		F[i]=(F[i-1]*i)%M

def powe(a,k):
	if (k==0):
		return 1
	elif (a==1 or a==0):
		return a
	if (k%2==0):
		return powe((a*a)%M,k/2)%M
	else:
		return (a*powe((a*a)%M,(k-1)/2))%M

def mi(a):
	return powe(a,M-2)%M 

def nCr(n,r):
	a=F[n]
	b=mi(F[n-r])
	c=mi(F[r])
	ans=(a*b*c)%M
	return ans

def Lucas(n,r):
	if(n==0 and r==0):
		return 1
	a=n%M
	b=r%M
	if(a<b):
		return 0
	c=nCr(a,b)%M
	return (c*Lucas(int(n/M),int(r/M)))%M	

def A(n,N):
	a=Lucas(N+n,n)
	a=a-1
	return a%M

init()
t=int(input())
while(t):
	word = raw_input()
	word=map(int,word.split(' '))
	n=int(word[0])
	l=int(word[1])
	r=int(word[2])
	N=r-l+1
	ans = A(N,n)
	print ans
	t=t-1
	
#~ if(N%M == 0 and n%M ==0):
		#~ print int(N/M)*int(n/M)
	#~ else:	
	#~ #print "N= ",n,", n= ",N
		#~ 
	
