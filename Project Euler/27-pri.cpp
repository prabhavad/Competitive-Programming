#include<iostream>
#define MAX 10000000
using namespace std;
int p[1002];
int com[MAX+1]={0};
int isP(int a)
{
	if(a<0)
		return 0;
	if(a<MAX)
		return !com[a];
	else
		for(int i=2;i*i<=a;i++)
			if(a%i==0)
				return 0;
	return 1;
}
		
	
int get(int a,int b,int m)
{
	int t=0;
	if(!isP(m*m+a*m+b))
		return 0;
	else
		for(int i=m;;i++)
			if(isP(i*i+a*i+b))
				t=i;
			else
				return t;
}
int main()
{
	
	for(int i=2;i*i<=MAX;i++)
	{
		if(!com[i])
			for(int j=2*i;j<=MAX;j+=i)
				com[j]=1;
	}
	
	int j=0;
	for(int i=2;i<1000;i++)
		if(!com[i])
			p[j++]=i;

	int M=0,s=1;
	int *a=p;
	
	cout<<get(15,3,0)<<'\n';
	int A,B;
	for(int i=167;i>=0;i--)
		for(int j=0;j<1000;j++)
		{
			
			//cout<<i<<' '<<j<<" M,s = "<<M<<','<<s<<'\n';
			

			int m=get(j,a[i],0);

			int m1=get(j,-a[i],0);

			int m2=get(-j,a[i],0);

			int m3=get(-j,-a[i],0);
			if(M<m)
			{
				M=m;
				s=j*a[i];
				A=j;
				B=a[i];
			}
			if(M<m1)
			{
				M=m1;
				s=-j*a[i];
				A=j;
				B=-a[i];
			}
			if(M<m2)
			{
				M=m2;
				s=j*a[i];
				A=j;
				B=-a[i];
			}
			if(M<m3)
			{
				M=m3;
				s=j*a[i];
				A=-j;
				B=-a[i];
			}
		}
	cout<<'\n'<<M<<' '<<A<<' '<<B<<' '<<s<<'\n';
	
}
