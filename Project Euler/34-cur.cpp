#include<iostream>
using namespace std;
int f(int a)
{
	if(!a)
		return 1;
	else
		return a*f(a-1);
}
int cu(int a)
{
	int b=a,s=0;
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
	int s=0;
	for(int i=10;i<=10000000;i++)
		if(cu(i))
			s+=i;
	cout<<s<<'\n';
}
