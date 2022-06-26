#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,pre=0,x,ans=0;
		cin>>n;
		FOR(i,1,n){
			cin>>x;
			if(pre==0 and x!=0) ans++;
			pre=x;
		}
		cout<<ans<<'\n';
	}
	return 0;
}