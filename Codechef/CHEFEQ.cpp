#include<iostream>
#include<string.h>
#include<algorithm>
int abso(int a)
{
	if(a<0)
		return -a;
	else
		return a;
}
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		int a[100001],b[100001]={0},n,m=0;
		cin>>n;
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[a[i]]++;
		}
		for(int i=1;i<=100000;i++)
		{
			m=max(m,b[i]);
		}
		int k=n-m;
		cout<<k<<'\n';
	}
}
