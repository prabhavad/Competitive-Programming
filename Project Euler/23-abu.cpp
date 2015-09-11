#include<iostream>
using namespace std;
int a[38124]={0};
int b[38124]={0};
int is_abu(int a)
{
	int s=0;
	for(int i=1;i*i<=a;i++)
	{
		if(a%i == 0)
		{
			s+=i;
			if(i != a/i && i!=1)
				s+=(a/i);
		}
	}
	//cout<<a<<":"<<s<<'\n';
	if(s>a)
		return 1;
	else
		return 0;
}
int is_pos(int c)
{
	for(int i=0;a[i]<c;i++)
		if(b[c-a[i]])
		{
			//cout<<"("<<c-a[i]<<")"<<' ';
			return 1;
		}
	return 0;
}
int main()
{
	int j=0;
	for(int i=0;i<=38123;i++)
	{
		b[i]=is_abu(i);
		if(b[i])
			a[j++]=i;
	}
	
	cout<<a[j-1]<<'\n';
	long long sum=0;
	for(int i=1;i<=38123;i++)
	{
		
		if(!is_pos(i))
		{
			sum+=i;
			//cout<<i<<' ';
		}
	}
	cout<<sum<<'\n';
}
