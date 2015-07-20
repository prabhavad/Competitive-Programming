#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define loop1(i,n) for(int i=1;i<=n;i++)
#define loop2(i,n) for(int i=2;i<=n;i++)
#define loopy(n) for(int i=0;i<n;i++)
#define strloop(i,a) for(int i=0;a[i];i++)
#define print(a) cout<<a<<endl
#define swap(a,b) a=a+b; b=a-b; a=a-b
#define lcm(a,b) (a*b)/gcd(a,b)
#define MAX 100000
#define declaregcd int gcd(int a, int b) { if(b>a) swap(a,b);int r; while(b>0){r=a%b;if (r==0) return b; a=b; b=r; } return 1;}
#define declareprimes  int prime[MAX]={0}; void primes() {prime[1]=1; prime[2]=0;  for(int i=2;i<=sqrt(MAX);i++)  { if(!p[i])  for(int j=2*i;j<MAX;j+=i) p[j]=1;  }  }
using namespace std;
int main()
{
	iostream::sync_with_stdio(false);
    int t;
    cin>>t;
    loopy(t)
    {
		int n;
		cin>>n;
		loop(i,n)
		{
			int a,b;
			cin>>a>>b;
		}
		int p=1;
		loop2(i,n)
		{
			p=p^i;
		}
		print(p);
	
	}	
}
