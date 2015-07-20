#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Pair
{
	int m;
	int n;
	int c;
	Pair()
	{
		m=n=c=0;
	}
	Pair(int a,int b)
	{
		n=a;
		c=b;
	}
	Pair(int a,int b,int d)
	{
		m=a;
		n=b;
		c=c;
	}
	void init(int a,int b,int d)
	{
		m=a;
		n=b;
		c=c;
	}
};
int comp(Pair a,Pair b)
{
	return (a.c<b.c);
}
vector<Pair> V[1000001];
Pair P[1000001];
int M[1000001];
struct Graph
{
	void addEdge(int a,int b,int c)
	{
		Pair p(b,c);
		Pair q(a,c);
		V[a].push_back(p);
		V[b].push_back(q);
	}
};



int main()
{
	//Graph G;
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		P[i].init(a,b,c);
		//G.addEdge(a,b,c);
	}
	sort(P,P+m,comp);
	int cc=0;
	for(int i=m-1;i>=0;i--)
	{
		if(M[P[i].m]==0){
			M[P[i].m]=1;
			cout<<P[i].m<<' ';
			cc++;
		}
		if(cc==n/2)
			break;
		if(M[P[i].n]==0){
			M[P[i].n]=1;
			cout<<P[i].n<<' ';
			cc++;
		}
		if(cc==n/2)
			break;
	}
	if(cc!=n/2)
	{
		for(int i=n;i>=0 && cc<(n/2);i--)
			if(M[i]==0){
				cout<<i<<' ';
				cc++;
			}
	}
	
}
	
	
