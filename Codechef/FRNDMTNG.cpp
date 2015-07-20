#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double a,b,c,d;
		cin>>b>>a>>d>>c;
		d=-d;
		double a1=b*a;
		double a2,a3;
		if(b-c <= 0)
			a2=0;
		else if(b-c <= a)
			a2 = (b-c)*(b-c)/2.0;
		else
			a2 = (b-c)*a - (a*a/2.0);
		if(a+d <= 0)
			a3=0;
		else if(a+d <= b)
			a3 = (a+d)*(a+d)/2.0;
		else{
			a3 = (b*(-d)) + b*b/2.0;
			a3 = a1-a3;
		}
		
		double A = a1 - a2 - a3;
		A = A/a1;
		//cout<<a1<<' '<<a2<<' '<<a3<<'\n';
		cout<<fixed<<A<<'\n';
	}
}
