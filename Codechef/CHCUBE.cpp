#include<iostream>
#define q(e,f,g) (c[e]==c[f] && c[f]==c[g])
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int c[6];
		char a[10];
		for(int i=0;i<6;i++){
			cin>>a;
			if(a[0]=='b' && a[2]=='u')
				c[i]=1;
			else if(a[0]=='b' && a[2]=='a')
				c[i]=2;
			else if(a[0]=='g')
				c[i]=3;
			else if(a[0]=='y')
				c[i]=4;
			else if(a[0]=='r')
				c[i]=5;
			else if(a[0]=='o')
				c[i]=6;
		}
		if( q(4,0,3) || q(4,3,1) || q(4,2,1) || q(4,0,2) || q(5,0,3) || q(5,3,1) || q(5,2,1) || q(5,0,2) )
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
