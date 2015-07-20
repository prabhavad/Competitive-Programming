#include<iostream>
using namespace std;
char a[]={1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
int main()
{
    char s[110];
    int n,k=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;k=0;
        for(char *j=s;*j!='\0';j++)
            k+=a[*j-'A'];
        cout<<k<<endl;
    }
    return 0;
}
