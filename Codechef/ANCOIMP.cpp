#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int a[1001][1001];

int n,g=0,t[1001]={0},c[1001];
int s[1001][2]={0};
int v[1001]={0};
int co[1001]={0};

struct tri{
	int wt;
	int g;
};
tri wt[1001];

int comp(tri a,tri b)
{
	return (a.wt > b.wt);
}

//   group  member colour
int G[1001] [1001] [2];

int Gr[1001][1001];
int y[1001];		

void reset(int n)
{
	g=0;
	for(int i=0;i<n;i++){
		t[i]=0;
		c[i]=0;
		v[i]=0;
		co[i]=0;
		s[i][0]=s[i][1]=0;
		for(int j=0;j<n;j++)
			Gr[i][j]=0;
	}
}

int is_bi(int a)
{
	queue<int> Q;
	Q.push(a);
	v[a]=1;
	co[a]=0;
	while(Q.empty()!=1)
	{
		int q = Q.front();		
		Q.pop();
		for(int j=0;j<n;j++)
		{
			if(Gr[q][j]){
				if(v[j]==0){
					c[j]=!c[q];
					v[j]=1;
					Q.push(j);
				}
				else{
					if(c[j]==c[q] && j!=q){
						//cout<<j<<' '<<q<<'\n';
						return 0;
					}
				}
			}
		}
	}
	return 1;
}



int color(int a,int c=0)
{
	queue<int> Q;
	Q.push(a);
	t[a]=-2;
	if(y[a]==-1)
		y[a]=c;
	while(Q.empty()!=1)
	{
		int te=Q.front();
		Q.pop();
		for(int i=0;i<n;i++){
			if(Gr[i][te] && i!=te && t[i]!=-2)
			{
				t[i]=-2;
				if(y[i]==y[te])
				{
					cout<<-1<<'\n';
					return 0;
				}
				y[i]=!y[te];
				
				Q.push(i);
			}
			if(t[i]==-2 && Gr[i][te] && y[i]==y[te])
			{
				cout<<-1<<'\n';
				return 0;
			}
		}
	}
	return 1;
}

int bfs(int a)
{
	queue<int> Q;
	Q.push(a);
	t[a]=g;
	c[a]=0;
	G[g][s[g][0]++][0]=a;
	
	while(Q.empty()!=1)
	{
		int te=Q.front();
		Q.pop();
		for(int i=0;i<n;i++){
			if(Gr[i][te] && i!=te && t[i]==-1)
			{
				if(y[i]==-1){
					t[i]=t[te];
					c[i]=!c[te];
					G[t[i]] [s[t[i]][c[i]]++] [c[i]] = i;
					Q.push(i);
				}
				else{
					//g not a group
					s[g][0]=s[g][1]=0;
					return color(i);
				}
			}
			
		}
	}
	g++;
	return 1;
}

int main()
{
	int tes;
	cin>>tes;
	while(tes--)
	{
		int one=0;
		int zero=0;
		
		cin>>n;
		reset(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
	
		//diagnal check
		for(int i=0;i<n;i++)
		{	
			if(i!=0)
				y[i]=-1;
			else
				y[i]=0;
				
			if(a[i][i]==1)
			{
				cout<<-1<<'\n';
				goto next;
			}
		}
		
		//initializing y[]
		for(int i=0;i<n;i++)
			if(a[0][i]==1)
				y[i]=1;
		
		//easy cases for y[i]
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				
				if(a[i][0]==1 && a[i][j]==1){
					if(y[j]==-1)
						y[j]=0;
					else if(y[j]==1){
						cout<<-1<<'\n';
						goto next;
					}
				}
			}
		}
		
		//~ cout<<"\nUsual:\n";
		//~ for(int i=0;i<n;i++)
			//~ cout<<y[i]<<' ';
		//~ cout<<'\n';
		
		//y[i]=dont_care cases
		for(int i=0;i<n;i++)
			if(y[i]==-1)
			{
				int f=1;
				for(int j=0;j<n;j++)
					if(a[i][j]==1){
						f=0;
						break;
					}
				if(f)
					y[i]=-2;
			}
		
		
		//~ cout<<"\nWith Dont cares:\n";
		//~ for(int i=0;i<n;i++)
			//~ cout<<y[i]<<' ';
		//~ cout<<'\n';
		
		//y[i]== -1 and y[i] = ?
		// Make a graph
		for(int i=0;i<n;i++){
			if(y[i]==-1){
				for(int j=0;j<n;j++){
					if(a[i][j]==1){
						if(y[j]==1)
							y[i]=0;
						else if(y[j]==0)
							y[i]=1;
						else if(y[j]==-1){
							Gr[i][j]=1;
							Gr[j][i]=1;
						}							
					}
				}
			}
		}
		
		//initially no groups for everybody
		for(int i=0;i<n;i++)
			t[i]=-1;
		
		//~ for(int i=0;i<n;i++)
		//~ {	for(int j=0;j<n;j++)
				//~ cout<<Gr[i][j];
			//~ cout<<'\n';
		//~ }
		
		//check bi-partite
		for(int i=0;i<n;i++)
			if(v[i]==0)
			{
				if(is_bi(i)==0)
				{
					cout<<-1<<'\n'; // NOT BI NOT BI NOT BI NOT BI NOT BI
					goto next;
				}
			}
		
		//put in groups and sort them
		for(int i=0;i<n;i++)
			if(t[i]==-1 && y[i]==-1)
				if(bfs(i)==0)
					goto next;
		
		
		for(int i=0;i<g;i++){
			wt[i].g=i;
			wt[i].wt=s[i][0]-s[i][1];
			if(wt[i].wt<0)
				wt[i].wt=-wt[i].wt;
		}
		sort(wt,wt+g,comp);
		
		
		for(int i=0;i<n;i++)
			if(y[i]==1)
				one++;
			else if(y[i]==0)
				zero++;
		
		//okay
				
		for(int j=0;j<g;j++)
		{
			int i=wt[j].g;
			if(s[i][0]<s[i][1] && s[i][0]>=1)
			{
				if(one < zero){
					color(G[i][0][0],0);
					one+=s[i][1];
					zero+=s[i][0];
				}
				else{
					color(G[i][0][0],1);
					one+=s[i][0];
					zero+=s[i][1];
				}
			}
			else
			{
				if(one < zero){
					color(G[i][0][0],1);
					one+=s[i][0];
					zero+=s[i][1];
				}
				else{
					color(G[i][0][0],0);
					one+=s[i][1];
					zero+=s[i][0];
				}
			}
		}
		for(int i=0;i<n;i++)
			if(y[i]==-2){
				if(one < zero){
					y[i]=1;
					one++;
				}
				else{
					y[i]=0;
					zero++;
				}
			}
		
		for(int i=0;i<n;i++)
			cout<<y[i]<<' ';
		cout<<'\n';
		next:;
	}
}
