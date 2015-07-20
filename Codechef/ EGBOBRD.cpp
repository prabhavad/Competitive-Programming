#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		long long n,k,a[100001];
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long long p=0,q=k;
		for(long long i=0;i<n;i++){
			if(a[i]<k){
				k=k-a[i];
				k--;
			}
			else if(a[i]==k){
				k=q;
				p++;
			}
			else{
				a[i]=a[i]-k;
				long long j;
				if(a[i]<=q)
					j=1;
				else
					j=a[i]/q + (a[i]%q != 0);
				p+=j;
				k=q*j-a[i];
				if(k>0)
					k--;
			}
		}
		if(q==k)
			cout<<p<<'\n';
		else
			cout<<p+1<<'\n';
	}			
}
