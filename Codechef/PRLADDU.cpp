#include<iostream>
#define MAX 100000
using namespace std;
struct data
{
    int pos;
    int val;
};
int abso(int a)
{
    if(a<0)
        return -a;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int n,temp,j=0,k=0;
        cin>>n;
        data v[MAX],d[MAX];
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(temp<0)
            {
                d[j++].val=(-temp);
                d[j-1].pos=i;
            }
            else
            {
                v[k++].val=temp;
                v[k-1].pos=i;
            }
        }
        int l1=j,l2=k;
        j=0;
        k=0;
        long long counter=0;
        while(j<l1&&k<l2)
        {
            if(d[j].val==v[k].val)
            {
                counter+=(d[j].val)*abso(d[j].pos-v[k].pos);
                j++;
                k++;
            }
            else if(d[j].val>v[k].val)
            {
                counter+=(v[k].val)*abso(d[j].pos-v[k].pos);
                d[j].val-=v[k].val;
                k++;
            }
            else
            {
                counter+=(d[j].val)*abso(d[j].pos-v[k].pos);
                v[k].val-=d[j].val;
                j++;
            }
        }
        cout<<counter<<endl;
    }
}
