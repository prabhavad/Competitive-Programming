#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a[100000];
		long long s=0,ss=0;
		
		bool f=1;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]>100)
				f=0;
			s+=a[i];
			if(a[i]!=0)
			ss+=a[i]-1;
		}
		if(f==1)
		{
		if(s<100)
			cout<<"NO"<<'\n';
		else if(s==100)
			cout<<"YES"<<'\n';
		else if(s<100+n && ss<100)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
		}
		else
			cout<<"NO"<<'\n';
	}
}
		
