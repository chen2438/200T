#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int N = 2e5+7;
int a[N],b[N];

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		FOR(i,1,n) cin>>a[i];
		FOR(i,1,n) b[i]=a[i]-a[i-1];
		int ans=0;
		FOR(i,2,n){
			if(b[i]>0){ans+=b[i];}
			if(b[i]<0){ans+=-b[i];b[1]-=-b[i];}
		}
		ans+=abs(b[1]);
		cout<<ans<<endl;
	}
	return 0;
}