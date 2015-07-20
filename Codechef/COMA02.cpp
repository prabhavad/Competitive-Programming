#include<iostream>
#include<algorithm>
using namespace std;
int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		long long  n,m,o,a[100001];
		cin>>n>>m>>o;
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		if(o>a[0])
		{
			cout<<"-1"<<'\n';
		}
		else
		{
			sort(a,a+n);
			long long count=0;

			for(int i=0;i<n;i++)
				if(a[i]>=o)
					count++;
			m=min(m,count);
			cout<<m<<'\n';
		}
	}
}
