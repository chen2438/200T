#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int MAXN=5e4+7;
int n,m,k;

struct node{int val,num;};

vector<node> a(MAXN),b(MAXN);

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		a.clear();
		b.clear();
		cin>>n>>m;
		int val,lena=0,lenb=0;
		FOR(i,0,n-1){
			cin>>val;
			int num=1;
			while(val%m==0 and val){
				num*=m;
				val/=m;
			}
			if(a[lena-1].val==val) a[lena-1].num+=num;
			else a[lena++]=(node){val,num};
		}
		cin>>k;
		FOR(i,0,k-1){
			cin>>val;
			int num=1;
			while(val%m==0 and val){
				num*=m;
				val/=m;
			}
			if(b[lenb-1].val==val) b[lenb-1].num+=num;
			else b[lenb++]=(node){val,num};
		}

		int eq=1;
		if(lena!=lenb) {cout<<"No\n";continue;}
		FOR(i,0,lena-1){
			if(a[i].val!=b[i].val or a[i].num!=b[i].num) {eq=0;break;}
		}
		if(eq==1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}