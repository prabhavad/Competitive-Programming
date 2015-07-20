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
#define strlen(a,l) int l; for(l=0;a[l];l++)
#define declaregcd int gcd(int a, int b) { if(b>a) swap(a,b);int r; while(b>0){r=a%b;if (r==0) return b; a=b; b=r; } return 1;}
#define declareprimes  int p[MAX]={0}; void primes() {p[1]=1; p[2]=0;  for(int i=2;i<=sqrt(MAX);i++)  { if(!p[i])  for(int j=2*i;j<MAX;j+=i) p[j]=1;  }  }


using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k,a=0,s=0;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{	cin>>a;
			s+=a;;
		}
		if(k==1){
			if(s%2)
				cout<<"even\n";
			else
				cout<<"odd\n";
		}
		else
		{
			//if(s%2==0)
				cout<<"even\n";
			//else
			//	cout<<"odd\n";
		}
	}
}
