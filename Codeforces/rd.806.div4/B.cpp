#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		string s;cin>>s;
		int a[30]={0};
		for(auto i:s) a[i-'A'+1]++;
		int ans=0;
		FOR(i,1,26) if(a[i]>0) ans+=a[i]+1;
		cout<<ans<<endl;
	}
	return 0;
}