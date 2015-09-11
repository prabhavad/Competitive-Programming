#include<iostream>
#include<iomanip>
#define ld long double
using namespace std;
ld answ=0;
ld dp[1000][10000];
ld solve(ld A[],int n,int k){
	if(n<0){
		return 1;
	}
	
	if(dp[n][k]==-1){
		ld q=0,w=0;
		if(n==0 && k==0){
			dp[0][0]=1.0-A[0];
		}
		else if(n==0 && k==1)
			dp[0][1]=A[0];
		
		else if (n+1<k)
			dp[n][k]=0;
		else{
			ld b=A[n];
			if(k>0)
				q=solve(A,n-1,k-1);
			ld c=(1.0-A[n]);
			w=solve(A,n-1,k);
			dp[n][k]= b*q + c*w;
		}
		
	
	}
	return dp[n][k];
}
int main()
{
	int t;
	cin>>t;
	for(int te=1;te<=t;te++){
		int n,k;
		cin>>n>>k;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<=k;j++)
				dp[i][j]=-1;
			
		static long double A[1000]={0};
		for(int i=0;i<n;i++)
			cin>>A[i];
		cout<<setprecision(2);
		solve(A,n-1,k);
		cout<<fixed<<"Case "<<te<<": "<<dp[n-1][k]<<'\n';
	}
}
