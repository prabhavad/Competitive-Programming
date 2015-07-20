   #include<iostream>
    #include<algorithm>
    #include<string.h>
    #include<math.h>
    #define loop(i,n) for(int i=0;i<n;i++)
    #define abso(a) if(a<0) a*=-1;
    #define loopy(n) for(int i=0;i<n;i++)
    #define strloop(i,a) for(int i=0;a[i];i++)
    #define print(a) cout<<a<<endl
    #define swap(a,b){ int swaap; swaap=a; a=b; b=swaap;}
    #define lcm(a,b) (a*b)/gcd(a,b)
    #define MAX 100000

    #define declaregcd int gcd(int a, int b) { if(b>a) swap(a,b);int r; while(b>0){r=a%b;if (r==0) return b; a=b; b=r; } return 1;}
    #define declareprimes  int p[MAX]={0}; void primes() {p[1]=1; p[2]=0;  for(int i=2;i<=sqrt(MAX);i++)  { if(!p[i])  for(int j=2*i;j<MAX;j+=i) p[j]=1;  }  }
    using namespace std;

    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            char a[MAX];
            cin>>a;
            int b=0,mm=0;
            strloop(i,a)
            {
                if(a[i]=='(')
                    b+=1;
                else
                    b-=1;
                if(mm<b)
                    mm=b;
            }
            for(int i=0;i<mm;i++)
                cout<<'(';
            for(int i=0;i<mm;i++)
                cout<<')';
            cout<<endl;
        }
    }
