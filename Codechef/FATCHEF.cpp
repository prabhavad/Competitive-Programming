#include<iostream>
#define MAX 100000
#define NN 1000000009
typedef long long iint;

using namespace std;
struct fe
{
    int p;
    int c;
    fe()
    {
        p=0;
        c=0;
    }
};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        iint n,m,k,l=0;

        cin>>n>>m;
        char p;
        int a[27]={0};
        fe pos[MAX];
        for(iint i=0;i<m;i++)
        {
            cin>>p>>k;
            a[k]=p-'A'+1;
        }
        for(iint i=1;i<27;i++)
        {
            if(a[i]!=0)
            {
                pos[l++].c=a[i];
                pos[l-1].p=i;
            }
        }
        iint l1=l;
        iint temp=1;
        for(iint i=1;i<l1;i++)
        {
            if(pos[i].c==pos[i-1].c)
            ;
            else
                temp*=((pos[i].p-pos[i-1].p)%NN);
            temp%=NN;
        }
        cout<<temp%NN<<endl;
    }
}
