#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--){
		long long a,t=0,f=0;
		cin>>a;
		for(int i=a; ;){
			if(i%2==0){
				i=i/2;
				t++;
			}
			else
				break;
		}
		for(int i=a; ;){
			if(i%5==0){
				i=i/5;
				f++;
			}
			else
				break;
		}
		if(t<f){
			while(t<f){
				a=a*4;
				t+=2;
			}
		}
		cout<<a<<'\n';
	}
}
