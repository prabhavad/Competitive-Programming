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
int getmax(int b[],int r)
{
	int m=0,p=-1;
	for(int i=0;i<26;i++){
		if(i!=r && b[i]>m){
			m=b[i];
			p=i;
		}
	}
	if(p==-1)
		return -1;
	b[p]--;
	return p;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char a[100001];
		cin>>a;
		int b[26]={0};
		for(int i=0;a[i];i++)
		{
			b[a[i]-'a']++;
		}
		int l=-1,flag=1;
		char c[100001];
		for(int i=0;a[i]&&flag;i++){
			int p=getmax(b,l);
			if(p==-1){
				cout<<-1<<'\n';
				flag=0;;
			}
			else{
				l=p;
				c[i]=(p+'a');
				c[i+1]=0;
			}
		}
		if(flag)
			cout<<c<<'\n';
	}
}
