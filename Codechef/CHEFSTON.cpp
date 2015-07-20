#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k,a[100000],b[100000];
		long long c[100000];
		
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		c[0]=(k/a[0])*b[0];
		long long mx=c[0];
		for(int i=0;i<n;i++)
		{
			c[i]=(k/a[i])*b[i];
			mx=max(mx,c[i]);
		}
		cout<<mx<<endl;
	}
}
