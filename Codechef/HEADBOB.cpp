#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define loopy(n) for(int i=0;i<n;i++)
#define strloop(i,a) for(int i=0;a[i];i++)
#define print(a) cout<<a<<endl
#define swap(a,b) a=a+b; b=a-b; a=a-b
#define lcm(a,b) (a*b)/gcd(a,b)
#define declaregcd int gcd(int a, int b){ if(b>a) swap(a,b);int r; while(b>0){r=a%b;if (r==0) return b; a=b; b=r; } return 1;}
declaregcd

using namespace std;
int main()
{
    int t;
    cin>>t;
    loopy(t)
    {
        int n,f=0;
        char a;
        cin>>n;
        loop(i,n)
        {
            cin>>a;
            if(a=='Y')
                f=1;
            else
                if(a=='I')
                    f=2;
        }
        if(f==0)
            print("NOT SURE");
        else
            if(f==1)
                print("NOT INDIAN");
            else
                print("INDIAN");
    }
}
