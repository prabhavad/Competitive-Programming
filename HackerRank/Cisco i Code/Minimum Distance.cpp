#include<iostream>
#include<climits>
#define ll long long
using namespace std;
ll f(ll a, ll b){
	ll c= a-b;
	if(c>0)
		return c*c*c;
	else
		return -c*c*c;
}
int main()
{
	int n,b[100000];
	ll h[10001]={0};
	cin>>n;
	ll m=INT_MIN;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		h[b[i]]++;
		m=max((int)m,b[i]);
	}
	ll K=0;
	ll VAL=INT64_MAX;
	for(int k=0;k<=m;k++){
		ll val=0;
		for(int i=0;i<=m;i++){
				val+= h[i]*f(k,i);
		}
		if(VAL>val){
			K=k;
			VAL=val;
		}
	}
	cout<<K;
}
