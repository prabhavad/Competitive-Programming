#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		char a[100001];
		cin>>a;
		int c=0;
		for(int i=0;a[i];i++)
		{
			c+= (a[i]-'a');
		}
		if(c%2==0)
			cout<<"Bob\n";
		else
			cout<<"Alice\n";
	}
}
