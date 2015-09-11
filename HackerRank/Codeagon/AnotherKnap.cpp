#include<iostream>
#include<climits>
#include<cmath>
#define ll long long
using namespace std;

ll dp[100001]={0};
int f(int a)
{
	if(a<0)
		return INT_MAX;
		
	if(dp[a]!=-1)
		return dp[a];
	else{
		return 0;
	}
	
}
	
int main()
{
	float n,m;
	cin>>n>>m;
	ll a=(n*(n+1))/2;
	if(m>a){
		cout<<-1;
		return 0;
	}
	else if(m<=n){
		cout<<1;
		return 0;
	}
		
	else{
		int c=0;
		while(n<m){
			c++;
			m=m-n;
			n--;
		}
		if(m==0)
		cout<<c;
		else
			cout<<c+1;
	}
}
