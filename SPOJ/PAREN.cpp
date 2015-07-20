#include<iostream>
#define ll long long
using namespace std;
ll t[1001][1001]={0};
ll f[1001][1001]={0};
char a[1001];
int l[1001];
ll F(int,int);
ll T(int i, int j)
{
	if(i==j){
		if(a[i]=='T')
			return 1;
		else
			return 0;
	}
	if(i>j)
		return 0;
	if(t[i][j]==0){
		for(int k=i;k<j;k++){
			if(l[k]==1){
				t[i][j]+=T(i,k)*T(k+1,j);
			}
			else if(l[k]==2){
				t[i][j]+=(T(i,k)+F(i,k))*(T(k+1,j)+F(k+1,j)) - F(i,k)*F(k+1,j);
			}
			else
				t[i][j]+=T(i,k)*F(k+1,j)+F(i,k)*T(k+1,j);
		}
	}
	return t[i][j];
}


ll F(int i, int j)
{
	if(i==j){
		if(a[i]=='F')
			return 1;
		else
			return 0;
	}
	if(i>j)
		return 0;
	if(f[i][j]==0){
		for(int k=i;k<j;k++){
			if(l[k]==1){
				f[i][j]+=(T(i,k)+F(i,k))*(T(k+1,j)+F(k+1,j)) - T(i,k)*T(k+1,j);
			}
			else if(l[k]==2){
				f[i][j]+=F(i,k)*F(k+1,j);
			}
			else
				f[i][j]+=T(i,k)*T(k+1,j)+F(i,k)*F(k+1,j);
		}
	}
	return f[i][j];
}

int main()
{	
	char tc[100];
	cin.getline(tc,100);
	int t=0;
	for(int i=0;tc[i];i++){
		t=t*10+tc[i]-'0';
	}
	
	while(t--){
		char S[1001];
		cin.getline(S,1001);
		int j=0,k=0;
		for(int i=0;S[i];i++){
			
			if(S[i]=='T' || S[i]=='F')
				a[k++]=S[i];
			else if(S[i]=='a')
				l[j++]=1,i+=3;
			else if(S[i]=='o')
				l[j++]=2,i+=2;
			else if(S[i]=='x') 
				l[j++]=3,i+=3;
			//cout<<i<<' '<<S[i]<<' '<<k<<' '<<j<<'\n';
		}
		for(int i=0;i<=k;i++)
		for(int ii=0;ii<=k;ii++) ::t[i][ii]=f[i][ii]=0;
		//cout<<k<<'\n';
		//~ for(int i=0;i<k;i++)
			//~ cout<<a[i]<<',';
		//~ cout<<'\n';
		//~ for(int i=0;i<j;i++)
			//~ cout<<l[i]<<',';
		//~ cout<<'\n';
		cout<<T(0,k-1)<<'\n';
	}
}
		
