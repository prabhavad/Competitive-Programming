#include<iostream>
using namespace std;
typedef long long int iint;
iint maxim(iint r,iint b,iint g)
{
    if(r>=b && r>= g)
        return r;
    if(g>=b && g>= b)
        return g;
    return b;
}
iint minim(iint r,iint b)
{
    if(r<b)
        return r;
    else
        return b;
}
iint operation(iint *r,iint *g,iint * b)
{
    iint max;
    iint R=*r;
    iint G=*g;
    iint B=*b;

    if(*r>=*b && *r>= *g)
    {
        (*r)/=2;


        return maxim(*r,*g,*b);
    }
    if(*b>=*r && *b>= *g)
    {
        (*b)/=2;


        return maxim(*r,*g,*b);
    }
    if(*g>=*b && *g>= *r)
    {
        (*g)/=2;

        return maxim(*r,*g,*b);
    }
}


int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        iint r,g,b,m;
        cin>>r>>g>>b>>m;
        iint t,R,G,B;
        cin>>R;
        for(iint i=1;i<r;i++)
        {
            cin>>t;
            if(t>R)
                R=t;
        }
        cin>>G;
        for(iint i=1;i<g;i++)
        {
            cin>>t;
            if(t>G)
                G=t;
        }
        cin>>B;
        for(iint i=1;i<b;i++)
        {
            cin>>t;
            if(t>B)
                B=t;
        }
        iint k;
        iint x=R,y=B,z=G;
        for(iint i=0;i<m-1;i++)
        {
            //op1(&x,&y,&z);
            operation(&R,&G,&B);
        }
        k=operation(&R,&G,&B);
        cout<<k<<endl;

    }
}
