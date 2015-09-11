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
#define MAX 1000001
#define declaregcd int gcd(int a, int b) { if(b>a) swap(a,b);int r; while(b>0){r=a%b;if (r==0) return b; a=b; b=r; } return 1;}
#define declareprimes  int p[MAX]={0}; void primes() {p[1]=1; p[2]=0;  for(int i=2;i<=sqrt(MAX);i++)  { if(!p[i])  for(int j=2*i;j<MAX;j+=i) p[j]=1;  }  }


using namespace std;
int get(int i, int j, float &n, float &d)
{
	if(i%10 == 0 || j%10==0)
		return 0;
	else if(i%10 == j%10)
	{
		n=i/10;
		d=j/10;
		return 1;
	}
	else if(i/10 == j/10)
	{
		n=i%10;
		d=j%10;
		return 1;
	}
	else if(i%10 == j/10){
		n=i/10;
		d=j%10;
		return 1;
	}
	else if(i/10 == j%10){
		n=i%10;
		d=j/10;
		return 1;
	}
	else
		return 0;
}
int main()
{
	for(float i=10;i<100;i++)
	{
		for(float j=i+1;j<100;j++){
			float n=1,d=1;
				
			if(get(i,j,n,d))
			{
				if(i*d - n*j == 0)
					cout<<i<<'/'<<j<<"  "<<n<<'/'<<d<<'\n';
			}
		}
	}
}
