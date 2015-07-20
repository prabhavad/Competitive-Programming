#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	char d[100002];
	char c[100002];
	for(int i=0;i<100000;i+=2)
	{
		c[i]='-';
		c[i+1]='+';
	}
	for(int i=0;i<100000;i+=2)
	{
		d[i]='+';
		d[i+1]='-';
	}
	while(t--)
	{
		char a[100000];
		
		cin>>a;
		int l=0;
		while(a[l++]);
		l=l-1;
		int m=0,n=0;
		for(int i=0;i<(l);i+=1)
		{
			if(a[i]!=c[i])
				m++;
			if(a[i]!=d[i])
				n++;
		}
		m=min(n,m);
		cout<<m<<endl;
	}
}
