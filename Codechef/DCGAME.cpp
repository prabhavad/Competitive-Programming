#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
struct pp{
	ll a;
	ll c;
	pp(){a=c=0;}
	
};
ll cmp(pp c,pp b){
	return c.a<b.a;
}
pp a[1000000];

long long bin(pp v[],ll st,ll ed,ll  a){
	long long m=(st+ed)/2;
	if(st<=ed){
		
		if(v[m].a==a)
			return m;
		else if(v[m].a>a && (m-1 >= 0) && v[m-1].a<a)
			return m;
		else if(v[m].a<a && (m+1 <= ed) && v[m+1].a>a)
			return m;
		else if(v[m].a<a)
			return bin(v,m+1,ed,a);
		else
			return bin(v,st,m-1,a);
	}
	else return -1;
}

void compute(ll  s,ll  e){
	
	if(s>e)
		return;
	if(s==e){
		a[s].c=1;
		return;
	}
	ll  m=s;
	for(ll  i=s;i<=e;i++){
		if(a[m].a<a[i].a)
			m=i;
	}
	a[m].c=(e-m+1)*(m-s+1);
	
	//cout<<"("<<m<<")"<<a[m].a<<' '<<a[m].c<<'\n';
	compute(s,m-1);
	compute(m+1,e);
}

ll s[1000000]={0};
ll t[1000000]={0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll  n,m;
	cin>>n>>m;
	
	for(ll  i=0;i<n;i++)
		cin>>a[i].a;
	compute(0,n-1);
	sort(a,a+n,cmp);
	ll  j=0;
	
	//cout<<'\n'<<a[0].a<<' '<<a[0].c<<'\n';;
	for(ll  i=1;i<n;i++){
		//cout<<a[i].a<<' '<<a[i].c<<'\n';
		if(a[j].a==a[i].a){

			a[j].c+=a[i].c;
		}
		else{
			//cout<<"("<<j<<") "<<a[j].a<<' '<<a[j].c<<'\n';
			j++;
			a[j].a=a[i].a;
			a[j].c=a[i].c;
		}
		//cout<<j<<' '<<a[j].a<<' '<<a[j].c<<'\n';
	
	}
	
	s[0]=0;
	t[j]=0;
	n=j+1;
	//cout<<'\n'<<a[0].a<<' '<<a[0].c<<'\n';
	for(ll  i=1,j=n-2;i<n;i++,j--){
		//cout<<a[i].a<<' '<<a[i].c<<'\n';
		s[i]=s[i-1]+a[i-1].c;
		t[j]=t[j+1]+a[j+1].c;
	}
	for(ll  yi=0;yi<m;yi++){
		char aa,b;
		ll  c;
		cin>>aa>>c;
		cin>>b;
		
		long long ans=0;
		
		ll  y;
		if(a[0].a>=c)
			y=0;
		else if(a[n-1].a<=c)
			y=n-1;
		else{
			y=bin(a,0,n-1,c);		
		}
		if(aa=='<'){
			if(c>a[y].a){
				
				ans=a[y].c+s[y];
			}
			else
				ans=s[y];
		}
		else if(aa=='>'){
			if(a[y].a>c)
				ans=t[y]+a[y].c;
			else
				ans=t[y];
		}
		else{
			if(a[y].a!=c)
				ans=0;
			else
				ans=a[y].c;
		}
		
		
		//cout<<y<<' '<<ans<<'\n';
		if(ans%2==1)
			cout<<b;
		else{
			if(b=='C')
				cout<<'D';
			else 
				cout<<'C';
		}
	
	}
	
}
