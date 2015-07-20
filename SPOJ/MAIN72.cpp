#include<iostream>
using namespace std;
int s[101][100001]={0};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a[101];
		cin>>n;
		int m=0;
		for(int i=0;i<n;i++)
		{	cin>>a[i];
			m=max(m,a[i]);
		}
		
		for(int i=0;i<n;i++)
			for(int j=0;j<=n*m;j++)
				s[i][j]=0;
		
		s[0][0]=1;
		s[0][a[0]]=1;
		for(int i=1;i<n;i++)
			for(int j=0;j<=n*m;j++){
				if(j-a[i]>=0)
				s[i][j]=max(s[i-1][j-a[i]],s[i-1][j]);
				else
					s[i][j]=s[i-1][j];
			}
		int su=0;
		for(int j=0;j<=n*m;j++)
			if(s[n-1][j]==1)
				su+=j;
		
		cout<<su<<'\n';
	}
}
