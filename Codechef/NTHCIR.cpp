#include<iostream>
#define M 10000003
using namespace std;

double ans[M+1];
double k[M+1];


int main()
{
	int t;
	cin>>t;
	long long n,p,m,b;
	cin>>n>>p>>m>>b;
	
	for(int i=1;i<5;i++){
		cin>>ans[i];
		k[i]=1.0/ans[i];
	}
	
	k[1]=-k[1];
	double c = 2.0*(k[1]+k[2]);
	double an=0;
	
	
	while(t--){
		long long a= (p*n)%m + b;
		double anse=(a-3)*k[4]-(a-4)*k[3] + c*(((a-4)*(a-3))/2.0);
		anse = 1.0/anse;
		an+=(anse);
		n=a;		
	}
	cout<<fixed<<an<<'\n';
}
