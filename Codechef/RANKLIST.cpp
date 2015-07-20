#include<iostream>
#include<string.h>
#include<algorithm>
#define ll long long
using namespace std;
int inR(ll d,int i,ll n,ll s)
{
	ll s1,s2;
	s1= (n-i)*(n-i+1);
	s1/=2;
	
	s2=s1;
	
	s1 += i*1;
	s2 += i*(n-i);
	
	if(s>=s1 && s<=s2)
		return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,s,k;
		cin>>n>>s;
		k= n*(n+1);
		k/=2;
		ll diff= k-s;
		if(diff==0)
		{
			cout<<0<<endl;
			goto l1;
		}
		for(int i=1;i<=n;i++)
		{
			if(inR(diff,i,n,s))
			{
				cout<<i<<endl;
				goto l1;
			}
		}
		l1:;
	}	
}
