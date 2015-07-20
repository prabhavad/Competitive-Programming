#include<iostream>
#include<algorithm>
#define ll long long
#define M 1000000007
using namespace std;
ll po(ll a,ll k){
	
	if(k==0) return 1;
	else if(k==1) return (a%M);
	else if(k&1) return ((a%M) * po(a*a,k/2))%M;
	else return (po((a*a)%M,k/2))%M;
}
int main()
{
	int t;
	cin>>t;
	ll pp[100001];
	pp[1]=2;
	pp[0]=1;
	for(int i=1;i<100001;i++)
		pp[i] = (pp[i-1]*2)%M;
	while(t--)
	{
		ll n,a[100001];
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		ll max=0,min=0;
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{   
			max = (max + ( pp[i] * a[i] )%M)%M;
			min = (min + ( pp[i] * a[n-i-1] )%M)%M;
		}   
		cout << (max-min+M)%M << '\n';
	}
}
