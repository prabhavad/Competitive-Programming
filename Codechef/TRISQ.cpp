#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int a[100000]={0};
    for(int i=4;i<=10000;i++)
    {
        a[i]=a[i-2]+(i-2)/2;
    }
    while(t--)
    {
        int n;
        cin>>n;
        cout<<a[n]<<endl;;
    }
}
