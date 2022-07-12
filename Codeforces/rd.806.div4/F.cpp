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

bool cmp1(const node &x,const node &y){
	return x.v<y.v;
}

bool cmp2(const node &x,const node &y){
	return x.idx<y.idx;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		a.clear();
		int n;cin>>n;
		FOR(i,1,n){
			int v;
			cin>>v;
			if(v>=i) continue;
			a.push_back({v,i});
		}
		b=a;
		sort(a.begin(),a.end(),cmp1);
		sort(b.begin(),b.end(),cmp2);
		// for(auto i:a)cout<<i.v<<" ";
		// cout<<endl;
		// for(auto i:b)cout<<i.v<<" ";
		// cout<<endl;
		int ans=0;
		for(auto i:a){
			int l=0,r=b.size()-1;
			while(l<r){
		        int mid=(l+r)/2;
		        if(b[mid].idx<i.v) l=mid+1;
		        else r=mid;
		    }
		    //cout<<r<<" ";
		    ans+=r;
		}

		cout<<ans<<endl;
	}
	return 0;
}