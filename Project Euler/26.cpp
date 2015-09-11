#include<iostream>
using namespace std;
int main()
{
	int a[1001]={0};
	for(int i=1;i<=1000;i++)
	{
		cout<<i<<'\n';
		int H[10000]={0};
		int p=i;
		int d=1;
		int o=0,po=0;
		while(d)
		{
			
			if(d < p)
			{
				d=d*10;
			}
			else
			{
				o++;
				int h=d%p;
				d=d%p;
				cout<<h<<' ';
				if(H[h]==0){
					H[h]=o;
				}
				else
				{
					po=H[h];
					break;
				}
			}
			
		}
		
		if(d==0)
			a[i]=0;
		else
			a[i]=o-po;
	}
	int m=0,p=0;
	for(int i=0;i<1000;i++)
	{
		if(m!=max(m,a[i]))
			p=i, m=max(m,a[i]);
		//cout<<a[i]<<'\n';
	}
	cout<<"Answer: "<<p<<'\n';
}
