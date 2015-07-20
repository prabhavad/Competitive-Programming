#include<iostream>
#include<string.h>
#include<algorithm>
#define ll long long
using namespace std;
ll f[10000001]={0};
ll fac[10000001]={0};
ll f1[10000001]={0};
ll m;

void init_fact()
{
	fac[1]=1;
	for(int i=2;i<=m;i++)
	{
		fac[i]= ( i * fac[i-1] )%m;
	}
}
ll fact(ll a)
{
	if(a<m)
		return fac[a];
	else
		return 0;
}
ll F1(ll a)
{
	if(a<m)
		return (f1[a])%m;
	else
		return f1[m]%m;
}
void init_f1()
{
	f1[1]=1;
	for(int i=2;i<=m;i++)
	{
		f1[i] = (f1[i-1] + (i * fact(i))%m )%m;
	}
}

ll F2(ll a)
{
	ll k;
	
	if(a%2==0)
	{
		k=( ((a/2)%m) * ((a+1)%m))%m;
	}
	else
		k=( ((a)%m) * ( ((a+1)/2)%m) )%m;
	 
	k = ( (k%m) * (a%m) )%m;
	return k;
}
ll F(ll a)
{
	return (F1(a) + F2(a))%m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	ll n,p;
	cin>>n>>m;
	init_fact();
	init_f1();
	ll s=0;
	for(int i=0;i<n;i++)
	{
		cin>>p;
		
		s= (s%m + F(p) ) % m;
	}
	cout<<s<<endl;
}
