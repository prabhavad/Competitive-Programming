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
    #define MAX 100000

    #define declaregcd int gcd(int a, int b) { if(b>a) swap(a,b);int r; while(b>0){r=a%b;if (r==0) return b; a=b; b=r; } return 1;}
    #define declareprimes  int p[MAX]={0}; void primes() {p[1]=1; p[2]=0;  for(int i=2;i<=sqrt(MAX);i++)  { if(!p[i])  for(int j=2*i;j<MAX;j+=i) p[j]=1;  }  }
    using namespace std;
    int main()
    {
        ios_base::sync_with_stdio(false);
        int n;
        cin>>n;
        char a[MAX];

        loopy(n)
        {
            cin>>a;
            int c=0;
            char b[26]={0};
            strloop(i,a)
            {
                //if(b[a[i]]==0)
                  //  c++;
                b[a[i]-'a']=1;
            }
            loopy(26)
                if(b[i]==0)
                    c++;
            print(26-c);
        }
        return 0;
    }
