#include<iostream>
using namespace std;
long long st[6000001]={0};
long long u[6000001]={0},n;
void update(long long i,long long a,long long b,long long l,long long r)
{
	
	if(a>b || l>r)
		return;
	//in range
	if(l<=a && b<=r){
		u[i]+=1;
		
	}
	// l r = 2 3
	// a b = 0 4
	else if(b<l || r<a)
		return;
	else
	{
		update(i*2,a,a+(b-a)/2,l,r);
		update(i*2+1,a+(b-a)/2+1,b,l,r);
	}	
}
long long v[6000001]={0};
void final_update(long long i=1,long long a=1,long long b=n){
	if(a==b)
		v[a]=u[i];
	else{
		u[2*i]+=u[i];
		u[2*i+1]+=u[i];
		final_update(2*i,a,a+(b-a)/2);
		final_update(2*i+1,a+(b-a)/2+1,b);
		
	}	
}
long long s[6000001]={0};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long t;
	cin>>t;
	while(t--){
		
		long long h;
		cin>>n>>h;
		
		for(long long i=0;i<=6*n;i++)
			u[i]=st[i]=v[i]=s[i]=0;
		for(long long i=0;i<n;i++){
			long long l,r;
			cin>>l>>r;
			l++;
			r++;
			
			update(1,1,n,l,r);
		}
		final_update();
		s[1]=v[1];
		
		for(long long i=2;i<=n;i++)
			s[i]=s[i-1]+v[i];
		long long m=0;
		for(long long i=1;i<=n-h+1;i++){
			//cout<<s[i+h-1]-s[i-1]<<' ';
			m=max(s[i+h-1]-s[i-1],m);	
		}	
		cout<<h*n-m<<'\n';
	}
}
