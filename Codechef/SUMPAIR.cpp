#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[100001];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        long long sum=0;
        for(int i=n-1;i>=1;i--){
            if(a[i]-a[i-1] < k){
                sum+=a[i];
                sum+=a[i-1];
                i--;
            }
        }
        cout<<sum<<'\n';
    }
}
