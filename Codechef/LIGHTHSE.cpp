#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		long long max_x=INT64_MIN,max_y=INT64_MIN,min_x=INT64_MAX,min_y=INT64_MAX;
		int maxi_y=0,mini_y=0;
		int maxi_x=0,mini_x=0;
		
		cin>>n;
		long long x[n],y[n];
		for(int i=0;i<n;i++)
		{	cin>>x[i]>>y[i];
			if(x[i]>max_x){
				max_x=x[i];
				maxi_x=i;
			}
			
			if(y[i]>max_y){
				max_y=y[i];
				maxi_y=i;
			}
			
			if(x[i]<min_x){
				min_x=x[i];
				mini_x=i;
			}
			
			if(y[i]<min_y){
				min_y=y[i];
				mini_y=i;
			}
		}
		//~ cout<<"Maximum Y and X\n";
		//~ cout<<max_y<<" ("<<maxi_y<<") \n";
		//~ cout<<max_x<<" ("<<maxi_x<<") \n";
		//~ cout<<"Minimum X and Y\n";
		//~ cout<<min_x<<" ("<<mini_x<<") \n";
		//~ cout<<min_y<<" ("<<mini_y<<") \n";
		//~ cout<<'\n'<<'\n';
		for(int i=0;i<n;i++){
			if(x[i]==min_x && y[i]==min_y)
			{
				cout<<1<<'\n'<<i+1<<" NE\n";
				goto next;
			}
			
			if(x[i]==min_x && y[i]==max_y)
			{
				cout<<1<<'\n'<<i+1<<" SE\n";
				goto next;
			}
			
			if(x[i]==max_x && y[i]==max_y)
			{
				cout<<1<<'\n'<<i+1<<" SW\n";
				goto next;
			}
			
			if(x[i]==max_x && y[i]==min_y)
			{
				cout<<1<<'\n'<<i+1<<" NW\n";
				goto next;
			}
		}
		if(x[maxi_y]>x[mini_y] && maxi_y!=mini_y)
			cout<<2<<'\n'<<maxi_y+1<<" SW\n"<<mini_y+1<<" NE\n";
		else if(x[maxi_y]<=x[mini_y] && maxi_y!=mini_y)
			cout<<2<<'\n'<<maxi_y+1<<" SE\n"<<mini_y+1<<" NW\n";
		next:;
	}
}
