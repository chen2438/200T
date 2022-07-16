#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
int a[200007];

void solve(){
	int n;cin>>n;
	FOR(i,1,n) cin>>a[i];
	int st=1;
	while(a[st]==0) st++;
	int ans=0;
	FOR(i,st,n-1){
		if(a[i]==0) ans++;
		else ans+=a[i];
	}
	cout<<ans<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
    while(T--){
        solve();
    }
	return 0;
}