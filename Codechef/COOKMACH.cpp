#include<iostream>
#include<cmath>
using namespace std;
int ab(int a){
	if(a<0)
		return -a;
	else
		return a;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(n==m){
			cout<<"0\n";
		}
		else if(pow(2,(int)log2(n))==n){	
			cout<<ab((int)log2(n)-(int)log2(m))<<'\n';	
		}
		else{
			int i=0;
			while(pow(2,(int)log2(n))!=n){
				++i;
				n/=2;
			}
			cout<<i+ab((int)log2(n)-(int)log2(m))<<'\n';
		}
	}
}
