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
		int n,k,x,y,P,C;
		int f=0;
		cin>>x>>y>>k>>n;
		
		for(int i=0;i<n;i++)
		{
			cin>>P>>C;
			if(x-y <= P && C<=k)
			{
				f=1;
			}
		}
		if(f==0 && y<x)
			cout<<"UnluckyChef\n";
		else if(f==1)
			cout<<"LuckyChef\n";
		else
			cout<<"UnluckyChef\n";
	}
}
