#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		string s;cin>>s;
		set<char> st;
		int ans=0;
		FOR(i,0,s.size()-1){
			if(st.count(s[i])) continue;
			if(st.size()==3) {ans++;st.clear();}
			st.insert(s[i]);
		}
		if(st.size()) ans++;
		cout<<ans<<endl;
	}
	return 0;
}