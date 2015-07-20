#include<iostream>
#include<stdio.h>
#define ll long long
using namespace std;

inline ll p2(ll a)
{
    return (ll)((ll)1<<a);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long c,s,k;
        cin>>s>>c>>k;
        
        
        if(!s && !c)
        {
            cout<<0<<'\n';
            continue;
        }
        
        if(s==0 && k==1)
        {
            ll a=p2(c+1)-p2(1);
            cout<<a<<'\n';
            continue;
        }
            
        if(k==1)
        {   
            ll h=p2(s);
            if(c<s) {
                
                cout<<(h +(ll)1);
            }
            
            else{
                
                cout<<( h +(ll)1+ p2(c+1) - p2(s) );
            }
            cout<<'\n';
            continue;
        }
        
        if(k>s)
        {
            cout<<0<<'\n';
            continue;
        }
        
        if(s==0)
        {
            cout<<0<<'\n';
            continue;
        }
        
        ll a=0;
        a += p2(s-k+1)+(ll)1;

        if(c>=(s-k+1))
            a += p2(s-k+1);
        cout<<a<<'\n';
    
    }
}
		
