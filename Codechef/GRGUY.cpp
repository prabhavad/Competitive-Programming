#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		string l[2];
		
		cin>>l[0]>>l[1];
		if(l[0][0]=='#' && l[1][0]=='#')
			cout<<"No\n";
		else{
			int ans=0,a=0;
			if(l[0][0]=='.'){
				
				int st=0;
				for(int i=0;l[0][i];i++){
					if(l[st][i]=='#'){
						if(l[!st][i+1] && l[!st][i+1]=='.'){
							st=!st;
							ans++;
						}
						else if(l[!st][i]=='.'){
							i--;
							st=!st;
							ans++;
						}
						else
						{
							cout<<"No\n";
							goto next;
						}
					}
				}
			}
			else
				ans=9999999;
			a=ans;
			ans=0;
			if(l[1][0]=='.'){
				
				int st=1;
				for(int i=0;l[0][i];i++){
					if(l[st][i]=='#'){
						if(l[!st][i+1] && l[!st][i+1]=='.'){
							st=!st;
							ans++;
						}
						else if(l[!st][i]=='.'){
							i--;
							st=!st;
							ans++;
						}
						else
						{
							cout<<"No\n";
							goto next;
						}
					}
				}
			}
			else ans=9999999;
			int b=min(ans,a);
			if(b==9999999)
				cout<<"No\n";
			
			else
				cout<<"Yes\n"<<b<<'\n';
			
		}
		next:
			;
	}
}
