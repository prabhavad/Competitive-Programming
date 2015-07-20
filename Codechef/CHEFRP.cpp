#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[100001];
		int m=999999,f=1;
		long long s=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]<2)
				f=0;
			m=min(m,a[i]);
			s+=a[i];
		}
		if(f)
			cout<<s-m+2<<'\n';
		else
			cout<<-1<<'\n';
	}
}
