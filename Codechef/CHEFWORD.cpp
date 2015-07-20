#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>

#define loop(i,n) for(int i=0;i<n;i++)

#define abso(a) if(a<0) a*=-1;
#define loopy(n) for(int i=0;i<n;i++)

#define print(a) cout<<a<<endl
#define swap(a,b){ int swaap; swaap=a; a=b; b=swaap;}
#define lcm(a,b) (a*b)/gcd(a,b)
#define MAX 100000
#define lld double
using namespace std;

void update(lld A[][26][26],int kk)
{
	for(int l=2;l<=kk;l++)
	{
		loop(i,26)
			loop(j,26)
				loop(k,26)
					A[l][i][j]+=A[l-1][i][k]*A[1][k][j];	
			
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	
	cout.precision(15);
	cin>>t;
	while(t--)
	{
	    int n,kk;
	    cin>>n>>kk;
	    char a[4],b[4];
	    cin>>a;
	    unsigned l=strlen(a);
	    lld A[101][26][26]={0};
	    
	    for(int i=0;i<26;i++)
	        for(int j=0;j<26;j++)
	            cin>>A[1][i][j];
	    
	    if(kk>=10)
			kk=10;
			
	   	update(A,kk);
	   		   	
	   	bool ii[27][27][27]={false};
	   	
	   	while(n--)
    	{
    		cin>>b;
    		unsigned lll=strlen(b);
    		if(lll==l)
    		{
				if(l==3)
				{	ii[b[0]-'a'][b[1]-'a'][b[2]-'a']=true;  }
				else if(l==2)
				{	ii[b[0]-'a'][b[1]-'a'][26]=true;   }
				else if(l==1)
				{	ii[b[0]-'a'][26][26]=true;     }
			
			}
       	}
       	
			lld p=0;
       		
			if(l==3)
			{	
				
			loop(i,26)
				loop(j,26)
					loop(k,26)
					{
						if(ii[i][j][k]==1)
							p+=(A[kk][a[0]-'a'][i])*(A[kk][a[1]-'a'][j])*(A[kk][a[2]-'a'][k]);
					}
			
			}	
			else if(l==2)
			{
			
			loop(i,26)
				loop(j,26)
					{
						if(ii[i][j][26]==1)
							p+=(A[kk][a[0]-'a'][i])*(A[kk][a[1]-'a'][j]);
					}
			
			}
			else if(l==1)
			{
			
			loop(i,26)
					{
						if(ii[i][26][26]==1)
							p+=(A[kk][a[0]-'a'][i]);
					}
			
			}	
			
		cout<<fixed<<p<<endl;
	}
}
