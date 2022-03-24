#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn=1e5+7;

struct node{
	int val,ind;
	bool operator< (const node &y)const{
		return val<y.val;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<node> a(maxn);
		FOR(i,1,n){
			cin>>a[i].val;
			a[i].ind=i;
		}
		if(n==1){cout<<"1 1\n";continue;}
		sort(a.begin()+1,a.begin()+n+1);
		cout<<a[1].ind<<" "<<a[n].ind<<'\n';

	}
	return 0;
}