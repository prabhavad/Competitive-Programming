#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,f=0;
		char s[101];
		cin>>s;
		cin>>n;
		int l=0;
		for(int i=0;s[i];i++,l++);
		long long cu=1,ans=0;
		for(int i=0;s[i];)
		{
			
			if(s[i]=='S'){
				cu+=1;
				if(cu+f>12*n){
					f=f-1;
					break;
				}
			}
			else{
				cu+=2;
				if(cu+f>12*n){
					f=f-2;
					break;
				}
			}
			i=(i+1)%l;
			if(i==0)
			{	
				f+=cu;
				ans+=(12*n-f+1);
				cu=0;
			}
		}
		cout<<ans<<'\n';
	}
}		
	
