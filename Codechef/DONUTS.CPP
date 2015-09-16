#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m,a[100000];
		cin>>n>>m;
		for(int i=0;i<m;i++)
			cin>>a[i];
		sort(a,a+m);
		int c=m,ans=0;
		for(int i=0;i<m;i++){
			if(c<=1)
				break;
			if(a[i]==1){
				ans+=1;
				if(c>2)
					c-=2;
				else
					break;
			}
			else{
				if(c > a[i]){
					c-=(a[i]+1);
					ans+=a[i];
				}
				else{
					ans+=(c-1);
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
