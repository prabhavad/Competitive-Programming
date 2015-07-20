#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--)	
	{
		long double N,i;
		scanf("%Lf %Lf",&N,&i);
		int n=(log2(i));
		n=n+1;
		long double d=pow(2,n-1);
		//cout<<(N/pow(2,n))<<endl;
		//cout<< (N/pow(2,(n/2))) <<endl;
		long double f=N/pow(2,n) + (i-d)* (N/pow(2,n-1));
		
		printf("%Lf\n",f);
	}
}
		
		
