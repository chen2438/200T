#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define MAXN (int)2e5+7
int a[MAXN];

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,k;cin>>n>>k;
		FOR(i,1,n) scanf("%d",&a[i]);
		if(k==1) cout<<(n-1)/2<<'\n';
		else{
			int ans=0;
			FOR(i,2,n-1) if(a[i]>a[i-1]+a[i+1]) ans++;
			cout<<ans<<'\n';
		}
	}
	return 0;
}