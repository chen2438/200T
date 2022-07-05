#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		if(n%2==0) cout<<n/2<<" "<<n/2<<" "<<0<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}