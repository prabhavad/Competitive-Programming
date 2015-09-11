#include<iostream>
#include<climits>
#define MAX INT_MIN
int st[600000]={0};
int build(int c[],int p=1,int a=0,int b=L)
{
	
	if(a>b)
		return MAX;
	if(a==b){
		st[p]=c[a];
		//cout<<a<<','<<b<<": "<<st[p]<<'\n';
		return st[p];
	}
	
	else{
		int x=build(c,2*p,a,a+(b-a)/2);
		int y=build(c,2*p+1,a+(b-a)/2+1,b);
		st[p]=min(x,y);
		//cout<<a<<','<<b<<": "<<st[p]<<'\n';
		return st[p];
	}
}
int main()
{
	int n,m;
	int a[100001];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
