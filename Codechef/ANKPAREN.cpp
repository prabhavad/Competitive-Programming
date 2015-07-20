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
#define MAX 100011
#define strlen(a,l) int l; for(l=0;a[l];l++)
#define declaregcd int gcd(int a, int b) { if(b>a) swap(a,b);int r; while(b>0){r=a%b;if (r==0) return b; a=b; b=r; } return 1;}
#define declareprimes  int p[MAX]={0}; void primes() {p[1]=1; p[2]=0;  for(int i=2;i<=sqrt(MAX);i++)  { if(!p[i])  for(int j=2*i;j<MAX;j+=i) p[j]=1;  }  }
char s[MAX];
struct data{
	int c,n;
	data()
	{c=0,n=0;}
};
int comp(data a, data b){
	
	if(a.c<b.c){
		for(int c1=a.c,c2=a.c;s[c1] && s[c2];c1++,c2++){
			
			if(c1==a.c)
				c1++;
			if(c2==b.c)
				c2++;
			if(s[c1] &&s[c2]){
				if(s[c1]>s[c2])
					return 0;
				else if(s[c1]<s[c2])
					return 1;
			}
		}
		return 0;
	}
	else{
		for(int c1=b.c,c2=b.c;s[c1] && s[c2];c1++,c2++){
			
			if(c1==a.c)
				c1++;
			if(c2==b.c)
				c2++;
			if(s[c1] &&s[c2]){
				if(s[c1]>s[c2])
					return 0;
				else if(s[c1]<s[c2])
					return 1;
			}
		}
		return 0;
	}
	
}



using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		int k,l=0;
		cin>>s;
		k=1;
		cin>>k;
		for(l=0;s[l];l++);
		int a=0;
		for(int i=0;i<l;i++)
		{
			if(s[i]=='(')
				a++;
			else
				a--;
			if(a<0)
				break;
		}
		
		if(a==0){
			data c[100011];
			int m=0,st=0;
			for(int i=0;i<l;i++){
				if(st==0){
					c[m++].c=i;
				}
				if(st==1 && s[i]==')')
				{	c[m++].c=i;
					st=2;
				}
				if(st==2 && s[i]=='(')
				{	c[m++].c=i;
					st=1;
				}
				if(s[i]=='(')
					st=1;
				else
					st=2;
				//c[m-1].n++;
				//cout<<m<<','<<N[m-1]<<'\n';
			}
			
			
		
			sort(c,c+m,comp);
			//~ for(int i=0;i<m;i++)
				//~ cout<<c[i].c<<"("<<c[i].n<<")"<<' ';
			//~ cout<<'\n';
			//~ //cout<<"Sorted\n";
			if(k>m)
				cout<<-1<<'\n';
			else{
				k--;
				
				
						for(int j=0;j<l;j++)
							if(j!=c[k].c)
								cout<<s[j];
						cout<<'\n';
						goto next;
					
			}
		}
		else{
			if(k==1)
				cout<<s<<'\n';
			else
				cout<<-1<<'\n';
		}
		next:;
	}
}
