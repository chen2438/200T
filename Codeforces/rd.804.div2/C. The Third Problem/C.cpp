#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long

const int N = 1e5+7;
const ll p = 1e9+7;

int f[N],g[N];//g 是 f 的反函数

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	cout<<"debug\n";
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		FOR(i,0,n-1) {cin>>f[i];g[f[i]]=i;}
		ll l,r,ans=1;
		l=r=g[0];
		FOR(i,0,n-1){
			if(g[i]<l) l=g[i];
			if(r<g[i]) r=g[i];
			cout<<"i="<<i<<",l="<<l<<",r="<<r<<endl;
			if(l<g[i] and g[i]<r) {
				ans=ans*(r-l+1-i)%p;
				cout<<(r-l+1-i)<<endl;
			}
			//cout<<l<<" "<<r<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}