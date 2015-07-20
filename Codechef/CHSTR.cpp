#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define M 1000000007
#define R 5001
using namespace std;
ll ncr[R][R]={0};
ll ans[R][R]={0};
void init_ncr()
{
	ncr[0][0]=1;
	ncr[1][0]=1;
	for(int i=1;i<R;i++)
		for(int j=0;j<=i;j++)
		{
			if(j==0)
				ncr[i][j]=1;
			else{
				ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j]);
				while(ncr[i][j]>=M)
					ncr[i][j]-=M*(ncr[i][j]/M);
			}
		}
}

ll f[R]={0};

int isLess(char *a, char *b)
{
	int i=0;
	for(i=0;a[i]&&b[i];i++)
	{
		if(a[i]>b[i])
			return 0;
		if(a[i]<b[i])
			return 1;
	}
	if(a[i]!=0 && b[i]==0)
		return 0;
	return 1;
}

ll Ncr(int n, int r){
	return ncr[n][r];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	init_ncr();
	while(t--)
	{
		ll n,q,g;
		cin>>n>>q;
		
		char s[R];
		cin>>s;
		g=(n+1)*n;
		g=g/2;
		char* suffix[R];
		for(int i=0;i<n;i++){
			suffix[i]=&s[i];
		}
		
		sort(suffix,suffix+n,isLess);
		
		//~ for(int i=0;i<n;i++){
			//~ cout<<suffix[i]<<'\n';
		//~ }
		
		int st[R]={0};
		
		ll rep[R]={0};

			
		for(int i=0;i<n;i++){
			int nr=1;
			for(int j=0;j<n-1;j++){
				if(suffix[j][i] == suffix[j+1][i] && st[j]==i && suffix[j+1][i]){
					st[j]++;
					if(j==n-2){
						rep[nr+1]++;
					}
					nr++;
				
				}
				else{
					rep[nr]++;
					nr=1;
				}				
			}
			
		}
		//~ for(int i=2;i<=n;i++)
			//~ cout<<rep[i]<<' ';
		//~ cout<<'\n';
		
		ll A[R]={0};
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++)
			{
				ans[i][j]=(rep[i]*ncr[i][j]);	
				//cout<<i<<j<<' '<<ans[i][j]<<' ';
				A[j]=(A[j]+ans[i][j]);
				if(A[j]>M)
					A[j]-=M*(A[j]/M);
			}
			//cout<<'\n';
		}
		
		while(q--){
			int k;
			cin>>k;
			if(k>n)
				cout<<0<<'\n';
			else if(k==1)
				cout<<(((n)*(n+1))/2)%M<<'\n';
			else cout<<A[k]<<'\n';
		}
	}
}				
