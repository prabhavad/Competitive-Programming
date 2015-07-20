#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int a[100001],n;
		cin>>n;
		cin>>a[0];
		long long m=a[0];
		for(int i=1;i<n;i++)
		{	cin>>a[i];
			if(a[i]>a[i-1])
				m+=a[i]-a[i-1];
		}
		cout<<m<<'\n';
	}
}
