#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long a[100001];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int h=floor(log2(a[n-1]));
	int k=n-1;
	for(int i=h;i>=0;i--){
		int f=0;
		long long ff;
		for(int j=k;j>=0;j--){
			if((a[j]>>i==1) && f==0){
				f=1;
				ff=a[j];
				//cout<<"Found "<<i<<','<<k<<','<<a[j]<<' ';
				swap(a[k],a[j]);
				k--;
			}
			else if((a[j]>>i==1) && f==1){
				//cout<<"Xored "<<a[j]<<' '<<ff<<'\n';
				a[j]^=ff;
			}
		}
		if(f)
		for(int j=n-1;j>k+1;j--)
			if((a[j]>>i)&1){	
				//cout<<"xor "<<a[j]<<' '<<i<<' '<<ff<<','<<k<<'\n';
				a[j]^=ff;
			}
		
	}
	long long xmx=0;
	for(int i=n-1;i>=0;i--){
		//cout<<a[i]<<' ';
		xmx=max(xmx,(xmx^a[i]));
	}
	cout<<xmx;
}
