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
    #define chef cout<<"Chef"<<'\n';
    #define mom cout<<"Mom"<<'\n';
    #define ll long long
    using namespace std;

    int main()
    {
        ios_base::sync_with_stdio(false);
        int t;
        cin>>t;
        loopy(t)
        {
            ll n,k;

            cin>>n>>k;
            ll a[MAX];
            ll sum=0;
            loop(i,k)
            {
                cin>>a[i];
                sum+=a[i];
            }
            sort(a,a+k);
            ll m=a[0]-1;
            m=(m*(m+1))/2;
            ll s=0;
            ll x=0;
            for(int i=0;i<k;i++)
            {
                //print(a[i]<<' '<<m);
                m=(a[i]*(a[i]-1))/2;
                if(m-s<a[i])
                {
                    x=a[i];
                    //print(x);
                    goto en;
                }
                else
                {
                    s+=a[i];

                }
            }
            if(x==0)
            {
                x=(n*(n+1))/2 +1 -s;
                
            }

            //x++;
            //
            en:
                //print(x);
                if(x%2==0)
                    mom
                else
                    chef
        }
    }
