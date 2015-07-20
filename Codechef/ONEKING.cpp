#include<iostream>
#include<algorithm>
using namespace std;
struct p{
int x;
int y;
};
int comP(p a,p b)
{
    return a.x<b.x;
}
int main()
{  ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--)
	{
        int n;
        cin>>n;
        p a[100000];
        for(int i=0;i<n;i++)
            cin>>a[i].x>>a[i].y;
        sort(a,a+n,comP);
        int m=a[0].y;
        long long co=1;
        for(int i=1;i<n;i++)
        {
            if(a[i].x>m)
            {
                
                co++;
                m=a[i].y;
            }
            else
                m=min(m,a[i].y);
        }
        cout<<co<<'\n';
	}
}
