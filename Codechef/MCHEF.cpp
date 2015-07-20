#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define Ll long long
using namespace std;

int sQ[1001]; //sqrt Tree
int a[100001]; //array . cost to remove
int ab[100001]; //array . value
int n,p;
Ll k[100001][501]={0};

void knp(int n,int W)
{
	for (int i = 0; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (i==0 || w==0)
				k[i][w] = 0;
			else if (a[i-1] <= w)
				k[i][w] = max(ab[i-1] + k[i-1][w-a[i-1]],  k[i-1][w]);
			else
				k[i][w] = k[i-1][w];
		}
	}
}

struct ju
{
	int l,r,c;
};

struct par
{
	int l,r;
	par(int a,int b){
		l=a,r=b;
	}
};




int comp(ju a, ju b)
{
	return a.c > b.c;
}
void update(int l,int r,int c)
{
	int si,ei;
	//first
	if(l%p != 0){
		if(sQ[l/p]!=0){
			for(int i=(l/p)*p;i<l;i++)
				a[i]=sQ[l/p];
			if(r<(l/p)*p+p)
			for(int i=r+1;i<(l/p)*p+p;i++)
				a[i]=sQ[l/p];
			sQ[l/p]=0;
		}
		if(r>=(l/p)*p+p){
			for(int i=l;i<(l/p)*p+p;i++)
				a[i]=c;
			//return;
		}
		else
		{	for(int i=l;i<=r;i++)
				a[i]=c;
			return;
		}
		si=l/p +1;
	}
	else
		si=l/p;
		
	//last
	if( (r+1)%p != 0){
		if(sQ[r/p]!=0){
			for(int i=r+1;i<((r/p)*p+p);i++)
				a[i]=sQ[r/p];
		}
		sQ[r/p]=0;
		for(int i=(r/p)*p;i<=r;i++)
			a[i]=c;
		
		ei=r/p-1;
	}
	else
		ei=r/p;
		
		
	//main
	for(int i=si;i<=ei;i++)
		sQ[i]=c;
	
	return;
}
void make(){
	for(int i=0;i<n;i++)
	{
		if(sQ[i/p]!=0)
			a[i]=sQ[i/p];
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int m,k;
		ju u[100001];
		cin>>n>>k>>m;
		
		
		Ll s=0;
		
		for(int i=0;i<n;i++)
		{	cin>>ab[i];
			a[i]=0;
			s+=ab[i];
		}
		
		for(int i=0;i<m;i++){
			int ll,rr,cc;
			cin>>ll>>rr>>cc;
			u[i].l=ll-1;
			u[i].r=rr-1;
			u[i].c=cc;	
		}
		sort(u,u+m,comp);
		//n>5000 || m>5000
		if(1){
			
			p = sqrt(n);
			for(int i=0;i<=(n/p)+1;i++)
				sQ[i]=0;
			for(int i=0;i<m;i++){
				if(u[i].c > k)
					continue;
				update(u[i].l,u[i].r,u[i].c);
			}
			
			make();
			
			for(int i=0;i<n;i++){
				if(ab[i]>0 || a[i]==-1 || a[i]==0){
					ab[i]=0;
					a[i]=0;
				}
				else
				{
					ab[i]=-ab[i];
				}
			}
			int j=0;
			for(int i=0;i<n;i++)
			{
				if(ab[i]!=0 && a[i]!=1000){
					ab[j]=ab[i];
					a[j]=a[i];
					j++;
				}
			}
			
			
			
			for(int i=0;i<=j;i++)
				for(int m=0;m<=k;m++)
					::k[i][m]=0;
			Ll ans=0;
			knp(j,k);
			ans=::k[j][k];
			cout<<s+ans<<'\n';
		}
		else{
			
			
		}
	}
}
