#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a=(k/2)*2+(k-(k/2));
		if(a>n){
			cout<<"No such string.\n";
			continue;
		}
		if((n-a)%2!=0)
		{	
			cout<<"No such string.\n";
			continue;
		}
		cout<<'a';
		for(int i=0;i<(n-a);i++)
			cout<<'a';
		char c='b';
		char e=k+'a'-1;
		for(char i=c;i<=e;i++){
			if((int)(i-'a')%2==1)
				cout<<i<<i;
			else
				cout<<i;
		}
		cout<<'\n';
	}
}
