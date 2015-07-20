#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define loop(n) for(int i=0;i<n;i++)
#define strloop(i,a) for(int i=0;a[i];i++)
#define print(a) cout<<a<<endl
#define swap(a,b) a=a+b; b=a-b; a=a-b
#define lcm(a,b) (a*b)/gcd(a,b)

int gcd(int a, int b)
{
    if(b>a)
        swap(a,b);
    int r;
    while(b>0)
    {
        r=a%b;
        if (r==0)
            return b;
        a=b;
        b=r;
    }
    return 1;
}

using namespace std;
/*

int maxsum(int a[100][100],int m,int n)
{
    int max=a[0][0]+ a[0][1] + a[1][0] + a [1][1];
    loop(i,m)
    {
        loop(j,n)
        {
            a[i][j]+=a[i][j+1]+a[i+1][j] + a[i+1][j+1];
            if(max<a[i][j])
                max=a[i][j];
        }
    }

}*/
int main()
{

    int t;
    cin>>t;
    loop(t){
        long long n,j;
        cin>>n;
        long long ans=n + (n*(n+1))/2 ;
        print(ans);
    }

}
