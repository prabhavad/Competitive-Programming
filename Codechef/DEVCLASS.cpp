#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#define ll long long
using namespace std;
inline int abso(int a)
{
	if(a<0)
		return -a;
	return a;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		
		ll type;
		int n=0,g=0,b=0;
		cin>>type;
		int a[100001];
		int B1[100001];
		
		int B2[100001];
		
		int G1[100001];
		int G2[100001];
		char c[100001];
		cin>>c;
		int l1,l2,k1,k2,L,K;
		l1=k1=l2=k2=L=K=0;
				
		for(int i=0;c[i];i++)
		{
			n++;
			a[i]= (c[i]=='G');
			
			if(a[i])
				g++;
			else
				b++;
			if(i%2==0 && a[i]==0)
				B1[k1++]=i;
			if(i%2==1 && a[i]==1)
				G1[l1++]=i;
			
			if(i%2==0 && a[i]==1)
				G2[l2++]=i;
			
			if(i%2==1 && a[i]==0)
				B2[k2++]=i;
			
			
		
		}

		if(n%2==0 && g!=b)
		{
			cout<<-1<<'\n';
			continue;
		}
		if(n%2==1 && (g!=b+1 && g!=b-1 ))
		{
			cout<<-1<<'\n';
			continue;
		}
			
		//cout<<n<<'\n';
		//cout<<g<<'\n';
		if(type==0)
		{
			
			int p=1,v=0,z=0;
			if(n%2==0){
				for(int i=0;i<n;i++)
				{
					if(a[i]!=p)
						z++;
					p=!p;
				}
				p=0;
				for(int i=0;i<n;i++)
				{
					if(a[i]!=p)
						v++;
					p=!p;
				}
				z=min(z,v);
				cout<<z/2<<'\n';
			}
			else
			{
				if(b>g)
					p=0;
				else
					p=1;
				for(int i=0;i<n;i++)
				{
					if(a[i]!=p)
						v++;
					p=!p;
				}
				cout<<v/2<<'\n';
			}
		}
		
		////TYPE 1 
		else if(type==1)
		{
		if(n%2==0)
		{
			
			ll c1=0,cost;
			for(int k=0;k<l1;k++)
				if(type==1)
						c1+=abso(G1[k]-B1[k]);
					else 
						c1+=(G1[k]-B1[k])*(G1[k]-B1[k]);
			
			cost=c1;
			c1=0;
			for(int k=0;k<l2;k++)
				if(type==1)
						c1+=abso(G2[k]-B2[k]);
					else 
						c1+=(G2[k]-B2[k])*(G2[k]-B2[k]);
			cost=min(c1,cost);
			//cout<<c1<<endl;
			
			cout<<cost<<endl;
			//cout<<"cost: "<<cost<<" COM: "<<com<<endl;
		
		}
		
		else
		{
			
			ll cost;
			cost=0;
			
			if(g>b)
			{
				ll c1=0;
				for(int k=0;k<l1;k++)
					if(type==1)
						c1+=abso(G1[k]-B1[k]);
					else 
						c1+=(G1[k]-B1[k])*(G1[k]-B1[k]);
				cost=c1;
				
			}
			else
			{
				ll c1=0;
				for(int k=0;k<l2;k++)
					if(type==1)
						c1+=abso(G2[k]-B2[k]);
					else 
						c1+=(G2[k]-B2[k])*(G2[k]-B2[k]);
				cost=c1;
			}	
			
			cout<<cost<<'\n';
			
		}
		}
		
		
		else
		{
		
		if(n%2==0)
		{
			int b[100001];
			for(int i=0;i<n;i++)
				b[i]=a[i];
			
			int p=1;
			long long cost=0;
			int gg=0,bb=0;
			for(int i=0;i<n;i++,p=!p)
			{
				
				gg=max(gg,i);
				bb=max(bb,i);
				if(a[i]!=p)
				{
					int j,st;
					if(p)
						st=gg;
					else
						st=bb;
					for(j=st;j<n;j++)
						if(a[j]==p)
						{
							break;
						}	
					if(p)
						gg=j;
					else
						bb=j;
						
					//if(type==1)
						cost+=abso(i-j);
					//else 
					//	cost+=(ll)((ll)(i-j)*(ll)(i-j));
					//cout<<i<<','<<j<<endl;
					swap(a[i],a[j]);
					/*for(int k=0;k<n;k++)
						cout<<a[k];
					cout<<endl;*/
				}
				
			}
			
			ll c1=cost;
			//
			cost=0;
			p=0;
			for(int i=0;i<n;i++)
				a[i]=b[i];
			gg=0,bb=0;
			for(int i=0;i<n;i++,p=!p)
			{
				gg=max(gg,i);
				bb=max(bb,i);
				if(a[i]!=p)
				{
					int j=i+1,st;
					if(p)
						st=gg;
					else
						st=bb;
					for(j=st;j<n;j++)
						if(a[j]==p)
						{	
							break;
						}
					if(p)
						gg=j;
					else
						bb=j;
					//if(type==1)
						cost+=abso(i-j);
					//else 
					//	cost+=(ll)((ll)(i-j)*(ll)(i-j));
					//cout<<i<<','<<j<<endl;
					swap(a[i],a[j]);
					/*for(int k=0;k<n;k++)
						cout<<a[k];
					cout<<endl;*/
				}
			}
			
			
			c1=min(c1,cost);
			
			for(int i=n-1;i>=0;i--)
				a[i]=b[n-i-1];
				
			p=1;
			cost=0;
			gg=0,bb=0;
			for(int i=0;i<n;i++,p=!p)
			{
				gg=max(gg,i);
				bb=max(bb,i);
				if(a[i]!=p)
				{
					int j,st;
					if(p)
						st=gg;
					else
						st=bb;
					for(j=st;j<n;j++)
						if(a[j]==p)
						{
							break;
						}	
					if(p)
						gg=j;
					else
						bb=j;
						
					//if(type==1)
						cost+=abso(i-j);
					//else 
					//	cost+=(ll)((ll)(i-j)*(ll)(i-j));
					//cout<<i<<','<<j<<endl;
					swap(a[i],a[j]);
					/*for(int k=0;k<n;k++)
						cout<<a[k];
					cout<<endl;*/
				}
				
			}
			
			c1=min(c1,cost);
			cost=0;
			p=0;
			
			for(int i=0;i<n;i++)
				a[i]=b[n-i-1];
			
			gg=0,bb=0;
			for(int i=0;i<n;i++,p=!p)
			{
				gg=max(gg,i);
				bb=max(bb,i);
				if(a[i]!=p)
				{
					int j=i+1,st;
					if(p)
						st=gg;
					else
						st=bb;
					for(j=st;j<n;j++)
						if(a[j]==p)
						{	
							break;
						}
					if(p)
						gg=j;
					else
						bb=j;
					//if(type==1)
						cost+=abso(i-j);
					//else 
					//	cost+=(ll)((ll)(i-j)*(ll)(i-j));
					//cout<<i<<','<<j<<endl;
					swap(a[i],a[j]);
					/*for(int k=0;k<n;k++)
						cout<<a[k];
					cout<<endl;*/
				}
			}
			
			cost=min(c1,cost);
			
			
			cout<<cost<<'\n';
			
		
		}
		
		else 
		{
			int B[100001];
			for(int i=0;i<n;i++)
				B[i]=a[i];
				
			int p;
			ll cost=0;
			if(b>g)
				p=0;
			else
				p=1;
			
			int gg=0,bb=0;
			
			
			for(int i=0;i<n;i++,p=!p)
			{
				
				gg=max(gg,i);
				bb=max(bb,i);
				//cout<<i<<':'<<a[i]<<p<<'\n';
				if(a[i]!=p)
				{
					int j=i+1,st;
					if(p)
						st=gg;
					else
						st=bb;
					for(j=st;j<n;j++)
						if(a[j]==p)
						{
							
							break;
						}	
					if(p)
						gg=j;
					else
						bb=j;
						
					//if(type==1)
						cost+=abso(i-j);
					//else 
					//	cost+=((ll)(i-j)*(ll)(i-j));
					
					//cout<<i<<','<<j<<endl;
					swap(a[i],a[j]);
					/*for(int k=0;k<n;k++)
						cout<<a[k];
					cout<<endl;*/
				}
				
			}
			
			for(int i=0;i<n;i++)
				a[n-i-1]=B[i];
			
			ll c1=cost;
			if(b>g)
				p=0;
			else
				p=1;
			gg=0,bb=0;
			cost=0;
			
			for(int i=0;i<n;i++,p=!p)
			{
				
				gg=max(gg,i);
				bb=max(bb,i);
				//cout<<i<<':'<<a[i]<<p<<'\n';
				if(a[i]!=p)
				{
					int j=i+1,st;
					if(p)
						st=gg;
					else
						st=bb;
					for(j=st;j<n;j++)
						if(a[j]==p)
						{
							
							break;
						}	
					if(p)
						gg=j;
					else
						bb=j;
						
					//if(type==1)
						cost+=abso(i-j);
					//else 
					//	cost+=((ll)(i-j)*(ll)(i-j));
					
					//cout<<i<<','<<j<<endl;
					swap(a[i],a[j]);
					/*for(int k=0;k<n;k++)
						cout<<a[k];
					cout<<endl;*/
				}
				
			}
			
			cost=min(c1,cost);
			cout<<cost<<'\n';
		}	
		
			
		}	
			
	}
}
