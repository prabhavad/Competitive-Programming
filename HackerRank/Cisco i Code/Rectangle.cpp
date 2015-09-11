#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,w,x,y,z;
	cin>>a>>b>>c>>d;
	cin>>w>>x>>y>>z;
	int f=1;
	if(a>y || w>c)
		f=0;
	if(b < z || x<d)
		f=0;
	if(f)
		cout<<"overlap";
	else
		cout<<"no overlap";
}

