#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
 
bool is_pal(char *a, int size)
{
		for (int i=0;i<size;i++)
		{
				if( a[i]!=a[size-1-i])
						return false;
		}
		return true;
}
 
 
int main()
{
		ios_base::sync_with_stdio(false);
		int n;
		cin>>n;
		char a[100000];
 
		while(n--)
		{
				//char c;
				int l=0;
				cin>>a;
				l=strlen(a);
				/*c=getchar();
				while(c!='\n')
				{
						a[l++]=c;
						c=getchar();
				}	
				a[l]=0;
				l--;*/
				
				
				int f=1;
				int si=l;
				for(int i=0;a[i];i++,si-=2)				
				{
						if(a[i]!=a[l-1-i])
						{		
								f= (is_pal(a+i+1,si-1) || is_pal(a+i,si-1) );
								break;
						}
				
				}
				if(f==1)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
		}
}
