#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int m,x,y;
		cin>>m>>x>>y;
		x=x*y;
		int a[1000],o[101]={0};
		for(int i=0;i<m;i++)
			cin>>a[i];
		for(int i=0;i<m;i++)
			for(int j=0;j<=x;j++)
			{
				if(j+a[i] >0 && j+a[i] <= 100)	
					o[j+a[i]]=1;
				if(a[i]-j >0 && a[i]-j <= 100)	
					o[a[i]-j]=1;
			}
		int s=0;
		for(int i=1;i<=100;i++)
			if(o[i]==0)
				s++;
		cout<<s<<'\n';
	}
}
