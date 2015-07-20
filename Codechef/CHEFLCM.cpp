#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
	
	
			long long s=0;
			for(int i=1;(i*i)<=n;i++)
				if(n%i==0)
				{	if(i!=(n/i))
						s+=(i+n/i);
					else
						s+=i;
				}
			
			cout<<s<<'\n';
	
	
	
	}
}
