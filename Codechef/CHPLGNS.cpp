#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
struct tri{
	long long nu;
	ll o,a;
};
ll c_nu(tri a,tri b){
	return a.nu < b.nu;
}
ll c_a(tri a,tri b){
	return a.o < b.o;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,x[200002],y[200002];
		tri a[100001];
		cin>>n;

		for(ll i=0;i<n;i++){
			cin>>m;
			for(ll j=0;j<m;j++){
				cin>>x[j]>>y[j];
			}
			x[m]=x[0];
			y[m]=y[0];
			long long area=0;
			for(ll j=0;j<m;j++){
				area+= (x[j]*y[j+1] - y[j]*x[j+1]);
			}
			if(area<0)
				area=-area;
			a[i].nu=area;
			a[i].o=i;			
		}
		sort(a,a+n,c_nu);
		for(ll i=0;i<n;i++){
			a[i].a=i;
		}
		sort(a,a+n,c_a);
		for(ll i=0;i<n;i++)
			cout<<a[i].a<<' ';
		cout<<'\n';
	}
}
