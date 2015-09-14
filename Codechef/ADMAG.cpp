#include<iostream>
#include<cmath>
using namespace std;

	
int main()
{
	int t;
	cin>>t;
	long long f[89];
	f[0]=0,f[1]=1,f[2]=1;
	for(int i=3;i<89;i++)
		f[i]=f[i-1]+f[i-2];
	
	while(t--){
		long long n;
		cin>>n;
		long long a=sqrt(n);
		if(n<=10){
			if(n==5)
				cout<<4<<'\n';
			else
				cout<<(n/(a)) + a-1<<'\n';
		}
		else{
			for(int i=0;i<89;i++){
				if(n==f[i] || (n>f[i] && n<f[i+1]))
				{	cout<<i-1<<'\n';
					break;
				}
			}
		}
	}
}
