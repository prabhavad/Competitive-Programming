
def po(a,n):
	return a**n;


	
q = raw_input()
i,k,s=map(int,q.split())

r= raw_input()
c,d=map(float,r.split())



di=k-i;

if(di<0):
	di=-di;

co=float(-2-(3)**(.5));
M=[[1.0,co],[co,-1.0]];
t=[[1.0,co],[co,-1.0]];
I=[[1.0,0],[0,1.0]];
Arr=[[0,0],[0,0]]
flag=0;
if(i>k):
	flag=1;
	det=float(M[0][0]*M[1][1] - M[0][1]*M[1][0]);
	M[0][0]=t[1][1]/det;
	M[0][1]=-t[0][1]/det;
	M[1][0]=-t[1][0]/det;
	M[1][1]=t[0][0]/det;
	flag=1;

if(di%2==0):
	for i in range(2):
		for j in range(2):
			Arr[i][j]=I[i][j];

else:
	for i in range(2):
		for j in range(2):
			Arr[i][j]=M[i][j];


e=float(Arr[0][0]*c + Arr[0][1]*d);	
f=float(Arr[1][0]*c + Arr[1][1]*d);	
ans=float(e+f);



x=float((2)**.5);
y=float((3)**.5);


if(di%2==0):
	if(flag!=1):
		if(4*di-2*s>=0):
			ans*=po(x,4*di-2*s);
		else:
			ans/=po(x,-4*di+2*s);
	
	else:
		ans/=po(x,4*di+2*s);
		

else:
	if(flag!=1):
		ans*=(1-y);
		if(4*di-2*s-3>=0):
			ans*=po(x,4*di-2*s-3);
		else:
			ans/=po(x,-(4*di-2*s-3));
	
	if(flag):
		ans/=(1-y)
		if(4*di-3+2*s >=0):
			ans/=po(x,4*di-3+2*s);
		else:
			ans*=po(x,-(4*di-3+2*s));
	
print ans
