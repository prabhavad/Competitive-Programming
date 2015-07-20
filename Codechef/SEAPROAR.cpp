#include<iostream>
#include<stdio.h>
#include<bitset>
#define ll unsigned 
using namespace std;
ll x, y, z, w;
ll X; 
ll add(ll x, ll y)
{
     while (y != 0)
    {
        ll carry = x & y;  
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}



void srand1(unsigned S){
  X = S;
}

unsigned nextInteger1(void){
  X =  1103515245*X+12345;
  return ((X >> 16) & 32767);
}

void generator1(int N, unsigned S, int A[]){
  srand1(S);
  for(int i=1;i<=N;i++){
    A[i] = (nextInteger1() & 1); 
  }
}



void srand2(unsigned S){
  x = S;
  y = x * S; //x2
  z = y * S;
  w = z * S;
}

unsigned nextInteger2(void){
  unsigned t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin>>t;
	
	//compute();
	while(t--)
	{
		char b[200001];
		ll B[200001],N=0;
		cin>>b;
		int co=0;
		for(int i=1;b[i-1];i++)
		{	
			B[i]=b[i-1]-'0';
			if(B[i]) co++;
			N++;
		}
		
		//cout<<N<<' '<<(co<(N-co))<<'\n';	
		ll Sc=0,lim;	
		if(N<=500)
			lim=501;
		
		else
			lim=900001;
		
		ll l;	
		
		while((Sc^lim))
		{
		
			srand1(Sc);
			
			
			for(ll i=0;(i^N);i++){
				
				l = (nextInteger1() &1); 
				 
					if(l ^ B[i+1] )
						goto Next;
					
			}
			cout<<"LCG\n";
			goto nextCase;
			Next:
			Sc++;
			
		}
		cout<<"Xorshift\n";
		nextCase:;		
	}
}
