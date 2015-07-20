#include<iostream>
#define ll long long
#define M 1000000000
using namespace std;
ll ncr[4001][4001]={0};
ll nn[2001][2001];
ll sn[2001][2001];

void init_ncr()
{
	ncr[0][0]=1;
	ncr[1][0]=1;
	for(int i=1;i<4001;i++)
		for(int j=0;j<=i;j++)
		{
			if(j==0)
				ncr[i][j]=1;
			else
				ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j]) % M;
		}
}

int main()
{
	int t;
	cin>>t;
	init_ncr();
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		//cout<<"ncr: "<<ncr[n][m]<<'\n';
		for(int i=0;i<=m;i++){
			nn[i][1]=ncr[i+m-1][m-1];
			if(i==0)
				sn[i][1]=nn[i][1];
			else
				sn[i][1]=(nn[i][1] + sn[i-1][1])%M;
		}
		
		for(int i=0;i<=m;i++){
			for(int j=2;j<=n;j++){
				nn[i][j]=(nn[i][1]*sn[i][j-1])%M;
				if(i==0)
					sn[i][j]=nn[i][j];
				else
					sn[i][j]=(nn[i][j] + sn[i-1][j])%M;
			}
		}
		ll s=0;
		for(int i=0;i<=m;i++)
			s=(s+nn[i][n])%M;
		cout<<s<<'\n';
	}
}
