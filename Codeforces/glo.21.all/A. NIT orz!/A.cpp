#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	puts("debug");
	int T;cin>>T;
	while(T--){
		int n,z;cin>>n>>z;
		int ai,ans=0;
		FOR(i,1,n){
			cin>>ai;
			ans=max(ans,ai|z);
		}
		cout<<ans<<'\n';
	}
	return 0;
}