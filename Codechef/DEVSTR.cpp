#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		char a[100001];
		cin>>a;
		if(k==1)
		{
			int t=0,y=0;
			for(int i=0,j=0;a[i];j=!j,i++)
			{
				if(a[i]-'0'==j)
					t++;
				else
					y++;
			}
			
			int f=0;
			if(t>y){
				cout<<n-t<<'\n';
				f=0;
			}
			else{
				cout<<n-y<<'\n';
				f=1;
			}
			for(int i=0;a[i];i++,f=!f)
				cout<<f;
			cout<<'\n';
		}
		else
		{
			int z=0,l=0,an=0;
			for(int i=0;a[i];i++)
			{
				if(a[i]=='0'){
					l=0;
					z++;
				}
				else{
					l++;
					z=0;
				}
				if(l>k){
					an++;
					if(a[i+1]=='1')
					{	a[i]='0';
						l=0;
						z=1;
					}
					else
					{	a[i-1]='0';
						l=1;
						z=0;
					}
				}
				if(z>k){
					an++;
					if(a[i+1]=='0')
					{	a[i]='1';
						l=1;
						z=0;
					}
					else
					{	a[i-1]='1';
						l=0;
						z=1;
					}
				}
			}
			cout<<an<<'\n'<<a<<'\n';
		}
	}
}
			
