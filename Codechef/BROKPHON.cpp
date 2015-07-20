#include<iostream>
using namespace std;
int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	
	cin>>t;
	while(t--)
	{
		int n,a[100001],c=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
		{
			if(((i+1<n) && a[i]!=a[i+1]) || ((i-1 >= 0) && a[i]!=a[i-1]))
				c++;
		}
		cout<<c<<'\n';
	}
}
