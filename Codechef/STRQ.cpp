#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#define ll long long

using namespace std;

ll  T1[1000001]={0};
ll  T2[1000001]={0};
ll  T3[1000001]={0};
ll  T4[1000001]={0};
ll  T5[1000001]={0};
ll  T6[1000001]={0};
ll  T7[1000001]={0};
ll  T8[1000001]={0};
ll  T9[1000001]={0};
ll T10[1000001]={0};
ll T11[1000001]={0};
ll T12[1000001]={0};
ll c[1000001]={0};
ll h[1000001]={0};
ll e[1000001]={0};
ll f[1000001]={0};

void init(char a[])
{
	if(a[0]=='c') c[0]=1;
	if(a[0]=='h') h[0]=1;
	if(a[0]=='e') e[0]=1;
	if(a[0]=='f') f[0]=1;
	//int LLL=strlen(a);
	
	for(ll i=1;a[i];i++)
	{
		c[i]=c[i-1] + (a[i]=='c');
		h[i]=h[i-1] + (a[i]=='h');
		e[i]=e[i-1] + (a[i]=='e');
		f[i]=f[i-1] + (a[i]=='f');
		// c h e f c h e h c 
		// 1 1 1 1 2 2 2 2 3
		// 0 1 1 1 1 3 3 5 5
		T1[i]=T1[i-1] + c[i-1] * (a[i]=='h');
		T2[i]=T2[i-1] + c[i-1] * (a[i]=='e');
		T3[i]=T3[i-1] + c[i-1] * (a[i]=='f');
		T4[i]=T4[i-1] + h[i-1] * (a[i]=='c');
		T5[i]=T5[i-1] + h[i-1] * (a[i]=='e');
		T6[i]=T6[i-1] + h[i-1] * (a[i]=='f');
		T7[i]=T7[i-1] + e[i-1] * (a[i]=='c');
		T8[i]=T8[i-1] + e[i-1] * (a[i]=='h');
		T9[i]=T9[i-1] + e[i-1] * (a[i]=='f');
		T10[i]=T10[i-1] + f[i-1] * (a[i]=='c');
		T11[i]=T11[i-1] + f[i-1] * (a[i]=='h');
		T12[i]=T12[i-1] + f[i-1] * (a[i]=='e');	
	}	
}
ll func(char s,char ee,ll l,ll r)
{
	ll *p;
	ll *q, *rr;
	if(s=='c' && ee=='h') p = T1, q=c, rr=h;
	if(s=='c' && ee=='e') p = T2, q=c, rr=e;
	if(s=='c' && ee=='f') p = T3, q=c, rr=f;
	if(s=='h' && ee=='c') p = T4, q=h, rr=c;
	if(s=='h' && ee=='e') p = T5, q=h, rr=e;
	if(s=='h' && ee=='f') p = T6, q=h, rr=f;
	if(s=='e' && ee=='c') p = T7, q=e, rr=c;
	if(s=='e' && ee=='h') p = T8, q=e, rr=h;
	if(s=='e' && ee=='f') p = T9, q=e, rr=f;
	if(s=='f' && ee=='c') p = T10, q=f, rr=c;
	if(s=='f' && ee=='h') p = T11, q=f, rr=h;
	if(s=='f' && ee=='e') p = T12, q=f, rr=e;
	
	if(l!=0)
	return (p[r]-p[l-1])-q[l-1]*(rr[r]-rr[l-1]);
	
	return p[r];
}
		
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char a[1000001],st,en;
	
	cin>>a;
	
	init(a);
	ll q,l,r;
	
	cin>>q;
	while(q--)
	{
		cin>>st>>en>>l>>r;
		l--;
		r--;
		cout<<func(st,en,l,r);
		cout<<'\n';
	}
}
