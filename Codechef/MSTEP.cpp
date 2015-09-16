
#include<iostream>
using namespace std;
long long v(long long a){
	if(a<0)
		return -a;
	else return a;
}

long long x[250000];
long long y[250000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int a;
				cin>>a;
				x[a]=i;
				y[a]=j;
			}
		long long ans=0;
		for(int i=1;i<n*n;i++)
		{
			ans+= v(x[i]-x[i+1])+v(y[i]-y[i+1]);
		}
		cout<<ans<<'\n';
	}
}
