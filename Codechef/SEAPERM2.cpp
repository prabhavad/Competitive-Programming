    #include<iostream>
    #include<algorithm>
    #include<string.h>
    #include<math.h>
    #define loop(i,n) for(int i=0;i<n;i++)
    #define abso(a) if(a<0) a*=-1;
    #define loopy(n) for(int i=0;i<n;i++)
    #define strloop(i,a) for(int i=0;a[i];i++)
    #define print(a) cout<<a<<endl
    #define swap(a,b){ int swaap; swaap=a; a=b; b=swaap;}
    #define lcm(a,b) (a*b)/gcd(a,b)
    #define MAX 100000

    using namespace std;
    bool sameLine(int a[], int b[], int n)
    {
	for(int i=0; i<n; i++)
		if(a[i]!=b[i])
			return false;
	return true;
    }
    
    bool inArray(int a[],int b[][300],int n,int ll[])
    {
	for(int i=0;i<n;i++)
        {
            if(sameLine(a,b[i],n-1)&&!ll[i])
	    {
			ll[i]=1;
			return true;
            }
			        
	}
	return false;
	
    }

    void printArray2(int a[][300],int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                cout<<a[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    void printArray(int a[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void getPossible(int a[],int b[],int n)
    {
        for(int i=0;i<n-1;i++)
            b[i]=a[i]+1;
    }
    void insert1(int a[],int b[],int pos,int n)
    {
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(i==pos)
                b[i]=1;
            else
                b[i]=a[j++];
        }
    }
    void getFn(int a[],int b[],int kk,int n)
    {
        
            int k=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]<kk)
                    b[k++]=a[i];
                else if(a[i]>kk)
                    b[k++]=a[i]-1;

            }
            //cout<<"Function #"<<j<<endl;
            //printArray(b[j],n-1);
        


    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        int n,gp[300][300],po[300];
        int fn[300],pp[300];
	int t;
	cin>>t;

	while(t--)
	{
        cin>>n;
        
	loopy(n)
        {
            loop(j,n-1)
                cin>>gp[i][j];
        }
        
        for(int i=0;i<n;i++)
        {
            getPossible(gp[i],po,n);
            for(int j=0;j<n;j++)
            {
                insert1(po,pp,j,n);
                int ll[300]={0};
		int f=0;
		for(int k=1;k<=n;k++)   
		{	
			getFn(pp,fn,k,n);
			if(!inArray(fn,gp,n,ll))
			{
				f=1;
				goto tty;			
			}
		}
            	tty:;
		if(f==0)
		{
			printArray(pp,n);
			goto rt;
		}
            }
		
        }
        rt:;
	}
    }
