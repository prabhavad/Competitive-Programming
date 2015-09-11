#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
string a[3628801];
unsigned ss=0,l;
char c[11];
int en[i]
void f(unsigned i,stack<char> S,string M){
	if(M.size()==l){
		M.push_back(0);
		a[ss]=M;
		
		ss++;
		return;
	}
	cout<<S.size()<<' ';
	cout<<"String : ("<<M<<" ) "<<' '<<i<<'\n';
	cin.get();
	if(i<l){
	//case 1, push in stack and continue
	S.push(c[i]);
	f(i+1,S,M);
	
	S.pop();
	//case 2, put in string
	M.push_back(c[i]);
	f(i+1,S,M);
	M.pop_back();
	}
	//case 3, pop from stack
	
	if(S.empty()!=1){
		char a=S.top();
		M.push_back(a);
		S.pop();
		f(i,S,M);
		M.pop_back(); 
	}
}
int main()
{

	cin>>c;
	stack<char> S;
	string M;
	l=strlen(c);
	f(0,S,M);
	cout<<ss<<'\n';
	//~ for(unsigned i=0;i<ss;i++)
		//~ cout<<a[i]<<'\n';
}
