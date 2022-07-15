#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

#define int long long
const int N=2e5+7;

struct node{
	int v,idx;
};

vector<node> a,b;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		a.clear();
		int n;cin>>n;
		FOR(i,1,n){
			int v; cin>>v;
			if(v>=i) continue;
			a.push_back({v,i});
		}
		b=a;
		sort(a.begin(),a.end(),[](node &x, node &y){return x.v<y.v;});
		sort(b.begin(),b.end(),[](node &x, node &y){return x.idx<y.idx;});
		int ans=0;
		for(auto i:a){
			int l=0,r=b.size()-1;
			while(l<r){
		        int mid=(l+r)/2;
		        if(b[mid].idx<i.v) l=mid+1;
		        else r=mid;
		    }
		    ans+=r;
		}
		cout<<ans<<endl;
	}
	return 0;
}