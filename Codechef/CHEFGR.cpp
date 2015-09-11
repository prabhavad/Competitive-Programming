#include<iostream>
using namespace std;

int main()
{
    int t,n,m,sum=0,a[101],max;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        sum=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        max=a[0];
        for(int i=0;i<n;i++)
            if(a[i]>max)
                max=a[i];
        for(int i=0;i<n;i++)
            m-=(max-a[i]);
        if(m==0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            if(m%n==0)
                cout<<"Yes"<<endl;
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
}
