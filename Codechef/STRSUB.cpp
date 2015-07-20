#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll abso(ll a)
{
	if(a<0)
		a= (-1)*a;
	return a;
}

int c_o[200001]={0};
int pp_o[200001]={0};
int p_o[200001]={0};
int c_z[200001]={0};
int pp_z[200001]={0};
int p_z[200001]={0};
int c[200001]={0};


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t1;
	cin>>t1;
	while(t1--)
	{
		ll n,k,q;
		char t;
		//cin>>k>>q;
		//char f[100001];
		//cin>>f;
		cin>>n>>k>>q;
		int i;
		for(i=1;i<=n;i++)
		{
			cin>>t;
			c[i]=t-'0';
		}
		
		
		if(k>=n)
		{
			ll l,r;
			for(int i=0;i<q;i++)
			{
				cin>>l>>r;
				cout<<(((r-l+1)*(r-l+2))/2)<<'\n';
			}
			continue;
		}
			
		if(c[1]==0)
			c_z[1]=1,c_o[1]=0;
		else if(c[1]==1)
			c_o[1]=1,c_z[1]=0;
			
		for(int i=2;i<=n;i++)
		{
			c_o[i]=c_o[i-1] + (c[i]);
			c_z[i]=c_z[i-1] + (!c[i]);
		}
		
		int o=1,z=1;
		
		for(int i=1;i<=n;i++)
		{
			if(c[i])
				p_o[o++]=i;
			if(!c[i])
				p_z[z++]=i;
		}
		//1010110101010
		//1122344556677
		//1,2 2,4 3,5 4,7
		for(int i=1;i<c_o[n];i++)
		{
			pp_o[i]=p_o[i+1]-1;			
		}
		pp_o[c_o[n]]=n;
		pp_z[c_z[n]]=n;
		for(int i=1;i<c_z[n];i++)
		{
			pp_z[i]=p_z[i+1]-1;			
		}
		
		//no problem
		
		int k_o=0,k_z=0;
		long long dp[100003]={0};
		for(int i=1;i<=k;i++)
		{
			dp[i]=(i*(i+1))/2;
			if(c[i])
				k_o++;
			else 
				k_z++;
		}
		
		for(int i=k+1;i<=n;i++)
		{
			ll ppo;
			if(c[i])
			{
				
				k_o++;
				//~ if(k_z==1)
				//~ {
					//~ if(i-k>=1)
						//~ ppo=k+1;
					//~ else
						//~ ppo= i;
					//~ 
				//~ }
				//cout<<"k_o= "<<k_o<<" k_z= "<<k_z<<'\n';
				if(k_z-k <=0 && k_o-k<=0)
					ppo= i;
				else if(k_z-k > 0 && k_o-k<=0)
					ppo= i-p_z[k_z-k];
				else if(k_z-k <= 0 && k_o-k > 0)
					ppo= i-(p_o[k_o-k]);
				else if(k_z-k > 0 && k_o-k > 0)	
					ppo= (i-max(p_o[k_o-k],p_z[k_z-k])) ;
			}
			else
			{
				k_z++;
				//cout<<"k_o= "<<k_o<<" k_z= "<<k_z<<'\n';
				//~ if(k_z==1)
				//~ {
					//~ if(i-k>=1)
						//~ ppo=k+1;
					//~ else
						//~ ppo= i;
					//~ 
				//~ }
				//~ 
				if(k_z-k <=0 && k_o-k<=0)
					ppo= i;
				else if(k_z-k >0 && k_o-k<=0)
					ppo= i-p_z[k_z-k];
				else if(k_z-k <= 0 && k_o-k > 0)
					ppo= i-p_o[k_o-k];
				else if(k_z-k > 0 && k_o-k > 0)	
				{
					ppo= (i-max(p_o[k_o-k],p_z[k_z-k])) ;
					
				}		
			}
			//cout<<i<<", "<<ppo<<'\n';
			dp[i]=dp[i-1] + ppo;
		}
	//~ 

		//~ cout<<"F_O: "; 
		//~ for(int i=1;i<=n;i++)
			//~ cout<<c_o[i]<<' ';
		//~ cout<<'\n';
	//~ 
		//~ cout<<"F_Z: "; 
		//~ for(int i=1;i<=n;i++)
			//~ cout<<c_z[i]<<' ';
		//~ cout<<'\n';
	//~ 
	//~ 
		//~ cout<<"CP: "; 
		//~ for(int i=1;i<=n;i++)
			//~ cout<<c[i]<<' ';
		//~ cout<<'\n';
		//~ 
		//~ cout<<"DP: "; 
		//~ for(int i=1;i<=n;i++)
			//~ cout<<dp[i]<<' ';
		//~ cout<<'\n';
		
		
		for(int i=0;i<q;i++)
		{
			ll l,r;
			ll ans=0;
			cin>>l>>r;
			//if(l==1)
			//	ans=dp[r];
			//else if(r==l)
			//	ans=1;
			
		
			if(r-l+1 <= k)
				ans=((r-l+1)*(r-l+2))/2;
			else if(((c_o[r]-c_o[l-1]) <= k) && (c_z[r]-c_z[l-1] <= k))
			{
				ans = ((r-l+1)*(r-l+2))/2;
			}
			// 010101 10110011010 1
			//        44567788        
			else 
			{
				int O=c_o[r]-c_o[l-1];
				int Z=c_z[r]-c_z[l-1];
				//int ko=c_o[r], kz=c_z[r];
				int mil;
				if(O>=k || Z>=k)
				{
					ll ab[4];
					ll yy;
					//int ooo,zzz,oo,zz;
					ab[0]=min((ll)p_o[k+c_o[l-1]],r);
					ab[1]=min((ll)pp_o[k+c_o[l-1]],r);
					ab[2]=min((ll)p_z[k+c_z[l-1]],r);
					ab[3]=min((ll)pp_z[k+c_z[l-1]],r);
					sort(ab,ab+4);
					//cout<<"ab: ";
					for(int i=0;i<4;i++)
					{
						yy=ab[i];
						//cout<<yy<<' ';
						//cout<<"(("<<c_z[yy]<<" - "<<c_z[l-1]<<")"<<" ("<<c_o[yy]<<" - "<<c_o[l-1]<<")) ";
						if(((c_z[yy]-c_z[l-1] <=k) && (c_o[yy]-c_o[l-1]<=k)))
							mil=yy;
					}
					//cout<<"\""<<mil<<"\" ";
					//cout<<'\n';	
					//int yy=max(ooo,zzz);
					//int aa=min(ooo,zzz);
					
					//~ cout<<"Poitions :"<< l<<", "<<r<<"\n";
					//~ cout<<ooo<<' ';
					//~ cout<<' '<<zzz<<' ';
					//~ cout<<' '<<oo<<' ';
					//~ cout<<' '<<zz<<' '<<'\n';;
					/*
					if(((c_z[yy]-c_z[l-1] <=k) && (c_o[yy]-c_o[l-1]<=k)))
						mil=yy;
					else if((c_z[aa]-c_z[l-1] <=k) && (c_o[aa]-c_o[l-1]<=k))
						mil=aa;
					else
					{
						ll y=max(oo,zz);
						if((c_z[y]-c_z[l-1] <=k) && (c_o[y] - c_o[l-1]<=k))
							mil=y;
						else
							mil=min(oo,zz);
					}*/
				}
				// 0001 1101001 0001
				/*else if(O>=k)
				{
					mil=min((ll)pp_o[k+c_o[l-1]],r);
				
				}
				else 
					mil=min((ll)pp_z[k+c_z[l-1]],r);
				*/
				//cout<<"Test Case: "<<t1<<'\n';
				//cout<<"MIL: "<<mil<<'\n';
				mil=mil-l+1;
				ll com=(ll)((ll)(mil)*(ll)(mil+1))/2;
				ll bak=dp[r]-dp[mil+l-1];
				ans=bak+com;
			}
			cout<<ans<<'\n';
			//cout<<"ANS: "<<ans<<'\n';
			//cout<<'\n';
		}
	}
}
