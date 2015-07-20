#include<iostream>
#include<algorithm>
using namespace std;

unsigned int gcd(unsigned int u, unsigned int v)
{
  int shift;
  if (u == 0) return v;
  if (v == 0) return u;
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
  }
  while ((u & 1) == 0)
    u >>= 1;

  do {

       while ((v & 1) == 0)
           v >>= 1;
if (u > v) {
         unsigned int t = v; v = u; u = t;}
       v = v - u;
     } while (v != 0);
 return u << shift;
}

int main()
{  ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--)
	{

		int  n,q,a[100001];
		int f[100001],l[100001];
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>a[i];


        l[n]=a[n];
        f[1]=a[1];

        for(int i=2;i<=n;i++)
            f[i]=gcd(f[i-1],a[i]);

        for(int i=n-1;i>=1;i--)
            l[i]=gcd(l[i+1],a[i]);

        for(int i=0;i<q;i++)
        {
            int ll,r;
            cin>>ll>>r;
            if(ll>1&&r<n)
                cout<<gcd(f[ll-1],l[r+1])<<"\n";
            else if(ll==1&&r<n)
                cout<<l[r+1]<<"\n";
            else if(ll>1&&r==n)
                cout<<f[ll-1]<<"\n";
            else
                cout<<1<<"\n";
        }
	}
}
