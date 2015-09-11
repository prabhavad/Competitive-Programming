#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#define ll long long
#define MAX INT_MIN
using namespace std;
vector < vector<int> > P;
int pp[300001];

//~ int pos(int a, int b)
//~ {
	//~ if(pp[a]==-1)
		//~ return L;
	//~ int c= (upper_bound(P[pp[a]].begin(), P[pp[a]].end(), b) - P[pp[a]].begin());
	//~ 
	//~ if(c<(int)P[pp[a]].size() && P[pp[a]][c]>b)
		//~ return P[pp[a]][c];
	//~ else
		//~ return L;
//~ }


int st[600001]={0};
int p[300001];
int q[300001];

int L;
int build(int c[],int p=1,int a=0,int b=L)
{
	
	if(a>b)
		return MAX;
	if(a==b){
		st[p]=c[a];
		//cout<<a<<','<<b<<": "<<st[p]<<'\n';
		return st[p];
	}
	
	else{
		int x=build(c,2*p,a,a+(b-a)/2);
		int y=build(c,2*p+1,a+(b-a)/2+1,b);
		st[p]=max(x,y);
		//cout<<a<<','<<b<<": "<<st[p]<<'\n';
		return st[p];
	}
}
int mini(int l,int r, int p=1,int a=0,int b=L)
{
	int ab;
	if(b<a)
		return (ab= MAX);
	if(r<a || b<l)
		return (ab= MAX);
	
	else if(l<=a && b<=r)
	{
		ab=st[p];
		return ab;
	}
	else{
		int A=mini(l,r,2*p,a,a+(b-a)/2);
		int B=mini(l,r,2*p+1,a+(b-a)/2+1,b);
		ab= max(A,B);
		return ab;
	}
	//~ cout<<"q :"<<l<<' '<<r<<". "<<a<<" to "<<b<<" Ans: "<<ab<<'\n';
	return ab;
}
int fr(int a,int l,int r){
	int i=pp[a];
	vector<int>::iterator lo,up;
	int u=(lower_bound(P[i].begin(),P[i].end(),l)-P[i].begin());
	int li=(lower_bound(P[i].begin(),P[i].end(),r)-P[i].begin());
	if(P[i][li]!=r)
		li--;
	return li-u+1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,a[100001];
	
	cin>>n>>m;
	L=n-1;
	for(int i=0;i<=100000;i++) pp[i]=-1;
	
	int si=0;
	for(int i=0;i<n;i++)
	{	
		cin>>a[i];
		if(pp[a[i]]==-1){
			P.push_back(vector<int>());
			P[si].push_back(i);
			pp[a[i]]=si;
			si++;
		}
		else
			P[pp[a[i]]].push_back(i);
		
	}
	build(a);
	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		int an=mini(l,r);
		
	}
}
