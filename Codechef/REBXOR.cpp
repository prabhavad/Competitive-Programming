
#include<iostream>
#define ll long long
#define B 5
using namespace std;


const int MN = 20000000;
struct trie {
  int n;
  int NN[MN][2];

  void clear() {
    n = 1;
    NN[0][0] = NN[0][1] = -1;
  }

  void insert(int x) {
    int no = 0;
    for (int i = 31; i >= 0; --i) {
      int iop = (x & (1 << i)) != 0;
      if (NN[no][iop] == -1) {
        NN[no][iop] = n;
        NN[n][0] = NN[n][1] = -1;
        n++;
      }
      no = NN[no][iop];
    }
  }

  int query(int x) {
    int no = 0;
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
      int iop = (x & (1 << i)) != 0;
      int flag_1 = 1;
      if (NN[no][iop ^ 1] == -1) {
        iop ^= 1;
        flag_1 = 0;
      }
      if (flag_1)
        ans += (1 << i);

      if (NN[no][iop ^ 1] == -1) while (true) {}
      no = NN[no][iop ^ 1];
    }
    return ans;
  }
};

long long r[500001]={0};
ll a[500001];
long long l[500001]={0};
trie t1,t2;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	t=1;
	while(t--){
	
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		
	}
	ll p=0;
	t1.clear();
	t1.insert(p);
	for(ll i=0;i<n;i++){
		p=p^a[i];
		t1.insert(p);
		ll q=t1.query(p);
		//cout<<q<<' '<<query(p,0,B,H)<<'\n';
		if(i!=0)
			l[i]=max(l[i-1],q);
		else
			l[i]=q;
	}
	p=0;
	t2.clear();
	t2.insert(p);
	for(ll i=n-1;i>=0;i--){
		p=p^a[i];
		t2.insert(p);
		ll q=t2.query(p);
		r[i]=q;
		if(i!=n-1)
		r[i]=max(q,(ll)r[i+1]);
	}
	long long mm=0;
	for(ll i=0;i<n-1;i++){
		//cout<<mm<<'\n';
		mm=max(l[i]+r[i+1],mm);
	}
	
	cout<<mm<<'\n';
	}
}
