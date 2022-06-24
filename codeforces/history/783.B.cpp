#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define mem(a) memset((a),0,sizeof(a))
#define int long long
const int INF=(1<<30);
const int maxn=2e5+7;
int a[maxn];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,m;
		int chair=0;
		cin>>n>>m;
		int max0=0,sum=0,min0=INF;
		//mem(a);
		FOR(i,1,n){
			cin>>a[i];
			max0=max(max0,a[i]);
			min0=min(min0,a[i]);
			sum+=a[i];
		}
		if(n>m){
			cout<<"NO\n";
			continue;
		}
		//sort(a+1,a+n+1,greater<int>());

		chair=max0+sum-min0+n;
		
		//chair+=n;
		if(chair<=m)cout<<"YES\n";
		else cout<<"NO\n";

	}
	return 0;
}