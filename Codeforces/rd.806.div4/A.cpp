#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		string s;cin>>s;
		if(s=="YES" or s=="YEs" or s=="Yes" or s=="yes" or s=="yES" or s=="yeS" or s=="YeS" or s=="yEs") cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}