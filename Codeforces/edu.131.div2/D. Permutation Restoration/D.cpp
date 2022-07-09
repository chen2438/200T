#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define PII pair<int,int>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<PII> v[n+7];
    int ans[n+7];
    FOR(i,1,n){
    	int b,l,r;cin>>b;
        l=i/(b+1)+1;
        if(b==0) r=n;
        else r=i/b;
        v[l].push_back({r, i});
    }
    set<PII> s;
    FOR(i,1,n){
    	for(auto it: v[i]) s.insert(it);
    	auto it=s.begin();
    	ans[(*it).second]=i;
    	s.erase(s.begin());
    }
    FOR(i,1,n) cout<<ans[i]<<" ";
    cout<<endl;
}


signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}