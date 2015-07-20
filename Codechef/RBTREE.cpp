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

    int t=0;
    int counting(int y,int x)
    {
        int c=0;
        int l1=log2(y);
        int l2=log2(x);

        int d=l1-l2;
        abso(d);
       // print(d);

        y/=pow(2,d);
        //print(y);
        //print(x);
        while(y!=x)
        {
            c++;
            x/=2;
            y/=2;
        }

       // print(c);
        return 2*c + d + 1;
    }

    int col(int y)
    {
        int a=log2(y);
        return !(a%2);
        if(a%2==0 && t==0)
            return 1;
        if(a%2==0 && t==1)
            return 0;
        else
            if(t==0)
                return 0;
            return 1;
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
        int q;
        cin>>q;
        loopy(q)
        {
            char a[3];
            cin>>a;
            int e,f;
            if(a[1]=='i')
            {
                if (t==1)
                    t=0;
                else
                    t=1;
            }
            else
            {
                int tag,y,x;
                if(a[1]=='b')
                    if(t==0)
                        tag=1;
                    else
                        tag=0;
                else
                    if(t==0)
                        tag=0;
                    else
                        tag=1;
                cin>>y>>x;
                if(y<x)
                    swap(y,x);
                int c=counting(y,x);
    //            print(c);
      //          print(tag);
        //        print(col(y));
                if(c%2==0)
                    print(c/2);
                else
                    if(tag==col(y))
                        print(c/2+1);
                    else
                        print(c/2);
            }
        }
        return 0;
    }
