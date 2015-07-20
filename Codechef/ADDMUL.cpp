#include<iostream>
#define Mo 1000000007
#define M(a) if (a<0) a=((a%Mo)+Mo)%Mo; else if (a>=Mo)	a%=Mo;
#define MAX 400001
#define ll long long
#define A (a+(b-a)/2)
#define B ((a+(b-a)/2)+1)
using namespace std;
int n;
ll sum[4*MAX]={0};
int amu[4*MAX]={0};
ll ad[4*MAX]={0};
ll a[4*MAX]={0};
ll mu[4*MAX]={1};
int vu[4*MAX]={0};
ll v[4*MAX];

void print()
{
	for(int i=1;sum[i];i++)
		cout<<sum[i]<<' '<<amu[i]<<' '<<vu[i]<<'\t'<<ad[i]<<' '<<mu[i]<<' '<<v[i]<<'\n';
}
void reset(int i)
{
	amu[i]=vu[i]=0;
	ad[i]=0;
	mu[i]=1;
}

ll build(int i=1, int a=1, int b=n)
{
	if(a==b){
		reset(i);
		sum[i]=::a[a];
		return ::a[a];
	}
	else{
		reset(i);
		sum[i] = build(2*i,a,a+(b-a)/2) + build(2*i+1,a+(b-a)/2 + 1,b);
		M(sum[i]);
		return sum[i];
	}
}

ll gsum(int i,int l,int r,int a=1,int b=n)
{
	//invalid range
	if(a>b || l>r)
		return 0;
	//not in range
	if(l>b || r<a)
		return sum[i];
	//same to same	
	if(a==b && l==a){
		reset(i);
		return sum[i];
	}
	//in range
	if(a>=l && b<=r){
		return sum[i];
	}
	//big range or half in range
	else {
		if(vu[i]==1){
			sum[2*i] = (A-a+1)*v[i];    M(sum[2*i]);
			sum[2*i+1] = (b-B+1)*v[i];  M(sum[2*i+1]);
			reset(2*i);
			reset(2*i+1);
			
			vu[2*i]=vu[2*i+1]=1;
			v[2*i]=v[2*i+1]=v[i];
			
			
			vu[i]=0;
			v[i]=0;
		}
		if(amu[i]==1){
			sum[2*i] = sum[2*i]*mu[i] + (A-a+1)*ad[i];
			sum[2*i+1] = sum[2*i+1]*mu[i] + (b-B+1)*ad[i];
			
			amu[2*i]=amu[2*i+1]=1;
			
			ad[2*i] = ad[2*i]*mu[i] + ad[i];
			ad[2*i+1] = ad[2*i+1]*mu[i] + ad[i];
			
			M(ad[2*i]);
			M(ad[2*i+1]);
			
			mu[2*i]*=mu[i];
			mu[2*i+1]*=mu[i];
			
			M(mu[2*i]);
			M(mu[2*i+1]);
			M(sum[2*i]);
			M(sum[2*i+1]);
			
			amu[i]=0;
		}
		reset(i);
		if(a==A)
			reset(2*i);
		if(b==B)
			reset(2*i+1);
		sum[i] = gsum(2*i,l,r,a,A)+gsum(2*i+1,l,r,B,b);
		M(sum[i]);
		return sum[i];	 
	} 
}
ll usum(int i,int l,int r,int a=1,int b=n)
{
	if(l>r || a>b) //invalid range
		return 0;
	
	// not in range
	else if(a>r || l>b)
		return 0;
	
	//in range
	else if(a>=l && b<=r)
		return sum[i];
	
	else{
		ll q=usum(2*i,l,r,a,A);
		q = q + usum(2*i+1,l,r,B,b);
		M(q);
		return q;
	}
}
ll Amu(int i,ll add,ll mul,int l,int r,int a=1,int b=n)
{
	//invalid range
	if(a>b || l>r)
		return 0;
	//not in range
	if(l>b || r<a)
		return sum[i];
	
	
	//in range
	if(a>=l && b<=r){
		amu[i]=1;
		ad[i]=ad[i]*mul;
		ad[i]=ad[i]+add;
		M(ad[i]);
		mu[i]=mu[i]*mul;
		M(mu[i]);
		//update sum
		sum[i]=sum[i]*mul;
		M(sum[i]);
		sum[i]=sum[i]+(b-a+1)*add;
		M(sum[i]);
		if(a==b)
			reset(i);
		return sum[i];
	}
	//big range or half in range
	else {
		if(vu[i]==1){
			reset(2*i);
			reset(2*i+1);
			sum[2*i] = (A-a+1)*v[i];
			sum[2*i+1] = (b-B+1)*v[i];
			M(sum[2*i]);
			M(sum[2*i+1]);
			vu[2*i]=vu[2*i+1]=1;
			v[2*i]=v[2*i+1]=v[i];
		}
		if(amu[i]==1){
			
			sum[2*i] = sum[2*i]*mu[i];
			M(sum[2*i]);
			sum[2*i] += (A-a+1)*ad[i];
			
			sum[2*i+1] = sum[2*i+1]*mu[i] ;
			M(sum[2*i+1]);
			sum[2*i+1] += (b-B+1)*ad[i];
			
			amu[2*i]=amu[2*i+1]=1;
			
			ad[2*i] = ad[2*i]*mu[i] + ad[i];
			ad[2*i+1] = ad[2*i+1]*mu[i] + ad[i];
			
			M(ad[2*i]);
			M(ad[2*i+1]);
			
			mu[2*i]*=mu[i];
			mu[2*i+1]*=mu[i];
			
			M(mu[2*i]);
			M(mu[2*i+1]);
			
			M(sum[2*i]);
			M(sum[2*i+1]);
			
		}
		reset(i);
		if(a==A)
			reset(2*i);
		if(b==B)
			reset(2*i+1);
		sum[i] = Amu(2*i,add,mul,l,r,a,A)+Amu(2*i+1,add,mul,l,r,B,b);
		M(sum[i]);
		return sum[i];	 
	} 
}

ll val(int i,ll v,int l,int r,int a=1,int b=n)
{
	//invalid range
	if(a>b || l>r)
		return 0;
	//not in range
	if(l>b || r<a)
		return sum[i];
	//in range
	if(a>=l && b<=r){
		reset(i);
		vu[i]=1;
		::v[i]=v;
		
		//update sum
		sum[i]=(b-a+1)*v;
		M(sum[i]);
		if(a==b)
			reset(i);
		return sum[i];
	}
	//big range or half in range
	else {
		if(vu[i]==1){
			reset(2*i);
			reset(2*i+1);
			sum[2*i] = (A-a+1)*::v[i];
			sum[2*i+1] = (b-B+1)*::v[i];
			M(sum[2*i]);
			M(sum[2*i+1]);
			vu[2*i]=vu[2*i+1]=1;
			::v[2*i]=::v[2*i+1]=::v[i];
			
		}
		if(amu[i]==1){
			
			sum[2*i] = sum[2*i]*mu[i];
			M(sum[2*i]);
			sum[2*i] += (A-a+1)*ad[i];
			
			sum[2*i+1] = sum[2*i+1]*mu[i] ;
			M(sum[2*i+1]);
			sum[2*i+1] += (b-B+1)*ad[i];
						
			
			amu[2*i]=amu[2*i+1]=1;
			
			ad[2*i] = ad[2*i]*mu[i] + ad[i];
			ad[2*i+1] = ad[2*i+1]*mu[i] + ad[i];
			
			M(ad[2*i]);
			M(ad[2*i+1]);
			
			mu[2*i]*=mu[i];
			mu[2*i+1]*=mu[i];
			
			M(mu[2*i]);
			M(mu[2*i+1]);
			
			M(sum[2*i]);
			M(sum[2*i+1]);
		}
		
		if(a==A)
			reset(2*i);
		if(b==B)
			reset(2*i+1);
			
		sum[i] = val(2*i,v,l,r,a,A)+val(2*i+1,v,l,r,B,b);
		M(sum[i]);
		reset(i);
		return sum[i];	 
	} 
}

int main()
{
	int q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build();
	while(q--){
		//print();
		int ty,x,y;
		ll v;
		cin>>ty>>x>>y;
		if(ty!=4)
			cin>>v;
		if(ty==1){
			Amu(1,v,1,x,y);
		}
		else if(ty==2)
			Amu(1,0,v,x,y);
		else if(ty==3)
			val(1,v,x,y);
		else{
			gsum(1,x,y);
			//cout<<sum[1]<<' ';
			cout<<usum(1,x,y)<<'\n';
		}
	}
}
