#include<iostream>
#include<iomanip>
#define ld long double
ld T= 1000000000.0;
using namespace std;


ld po(ld a,int n){
	if(n==0)
		return 1;
	else if(n==1)
		return a;
	else if(n&1)
		return a*po(a*a,n/2);
	else
		return (po(a*a,n/2));
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int m;
		ld p;
		cin>>m>>p;
		cout<<fixed<<setprecision(4);
		if(m==1){
			cout<<T<<' '<<0.0<<'\n';
		}
		else if(m==2){
			cout<<(T-p*T)<<' '<<p*T<<'\n';
		}
		else if(m>=3){
			ld cost=T*(1.0-po(-p,m))/(1.0+p);
			
			cout<<cost<<' '<<T-cost<<'\n';
		}
	}
}
