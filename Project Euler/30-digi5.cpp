#include<iostream>
using namespace std;
long long f(long long a)
{
	return a*a*a*a*a;
}
long long is(long long a)
{
	long long b=a;
	long long s=0;
	while(a)
	{
		s+=f(a%10);
		if(s>b)
			return 0;
		a=a/10;
	}
	if(s==b)
		return 1;
	else
		return 0;
}
	
int main()
{
	long long s=0;
	for(long long i=2;i<100000000;i++)
	{
		if(is(i)){
			s+=i;
			cout<<i<<'\n';
		}
	}
	cout<<s<<'\n';
}
	
