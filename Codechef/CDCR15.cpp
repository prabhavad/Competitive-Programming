#include<iostream>
int main()
{
	int t;
	std::cin>>t;
	while(t--)
	{
		int n,k,s=0,h=0,f=1;
		char c;
		std::cin>>n>>k;
		k--;
		for(int i=0;i<n;i++)
		{
			std::cin>>c;
			if(((c=='#')&& (s==0)))
			{
				h++;
				if(h>k)
				{
					f=0;
					//goto k;
					//return 0;
				}
			}
			if(c=='.')
				s=1;
			if(c=='#'&& s==1)
			{
				s=0;
				h=0;
				h++;
				if(h>k)
				{
					f=0;
					//std::cout<<"NO\n";
					//goto k;
					//return 0;
				}
			}
		}
		if(f==1)
			std::cout<<"YES\n";
		else
			std::cout<<"NO\n";
		
	}
}
