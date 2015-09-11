#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#define ll long long
#define loop(i,j,n) for(int i=(j);i<=(n);i++)
#define loopy(n) for(int i=0;i<n;i++)
#define strloop(i,a) for(int i=0;a[i];i++)
#define print(a) cout<<a<<endl
#define swap(a,b) { a=a+b; b=a-b; a=a-b;}
#define lcm(a,b) (a*b)/gcd(a,b)
#define MAX 100001
#define declaregcd int gcd(int a, int b) { if(b>a) swap(a,b);int r; while(b>0){r=a%b;if (r==0) return b; a=b; b=r; } return 1;}
#define declareprimes  int p[MAX]={0}; void primes() {p[1]=1; p[2]=0;  for(int i=2;i<=sqrt(MAX);i++)  { if(!p[i])  for(int j=2*i;j<MAX;j+=i) p[j]=1;  }  }


using namespace std;
int main()
{
	int two[MAX]={0},three[MAX]={0},five[MAX]={0},six[MAX]={0},seven[MAX]={0},ten[MAX]={0};
	for(int i=2;i<=100;i++)
	{
		two[i]=1;
		two[2*i]=1;
		two[3*i]=1;
		two[4*i]=1;
		two[5*i]=1;
		two[6*i]=1;
		
		three[i]=1;
		three[2*i]=1;
		three[3*i]=1;
		three[4*i]=1;
		
		five[i]=1;
		five[2*i]=1;
		
		six[i]=1;
		six[2*i]=1;
		
		seven[i]=1;
		seven[2*i]=1;
		
		ten[i]=1;
		ten[2*i]=1;
	}
	int c=81*99;
	for(int i=1;i<MAX;i++)
	{
		if(two[i]) c++;
		if(three[i]) c++;
		if(five[i]) c++;
		if(six[i]) c++;
		if(seven[i]) c++;
		
		if(ten[i]) c++;
	}
		
	cout<<c;	
	
	
}
