#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define ll long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		ll n,m;
		cin>>n>>m;
		cout<<1ll*m*(m+1)/2+m*(1ll*n*(n+1)/2 - 1)<<endl;
	}
	return 0;
}