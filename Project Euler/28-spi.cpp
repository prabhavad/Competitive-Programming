#include<iostream>
using namespace std;
int main()
{
	long long a1=3,a2=5,d1=4,d2=4,s1=0,s2=0;
	long long s=1001; 
	while(a1<=s*s)
	{
		//cout<<a1<<'\n';
		s1+=a1;
		a1+=d1;
		d1+=2;
	}
	while(a2<=s*s)
	{
		//cout<<a2<<'\n'<<a2+d2<<'\n';
		s2+=2*a2+d2;
		a2+=d2;
		d2+=4;
		a2+=d2;
	}
	cout<<s2+s1+1LL;
}
		
		
