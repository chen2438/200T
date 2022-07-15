#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

void solve(){
	int n,x;cin>>n>>x;
	int a[1007]={};
	FOR(i,1,2*n) cin>>a[i];
	sort(a+1,a+2*n+1);
	int ans=1;
	FOR(i,1,n){
		if(a[i+n]-a[i]<x) ans=0;
	}
	if(ans) cout<<"YES\n";
	else cout<<"NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
    while(T--){
        solve();
    }
	return 0;
}