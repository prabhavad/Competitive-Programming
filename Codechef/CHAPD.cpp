#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#define ll long long
#define loop(i,j,n) for(int i=(j);i<=(n);i++)
#define loopy(n) for(int i=0;i<n;i++)
#define strloop(i,a) for(int i=0;a[i];i++)
#define print(a) cout<<a<<endl
#define swap(a,b) { a=a+b; b=a-b; a=a-b; }
#define lcm(a,b) (a*b)/gcd(a,b)
#define MAX 1000001
#define declaregcd ll gcd(ll a, ll b) { if(b>a) swap(a,b);ll r; while(b>0){r=a%b;if (r==0) return b; a=b; b=r; } return 1;}
#define declareprimes  int p[MAX]={0}; void primes() {p[1]=1; p[2]=0;  for(int i=2;i<=sqrt(MAX);i++)  { if(!p[i])  for(int j=2*i;j<MAX;j+=i) p[j]=1;  }  }
declaregcd
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		while(1)
		{
			ll g=gcd(a,b);
			if(g==1)
				break;
			else
			{
				b=b/g;
			}
		}
		if(b==1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}
