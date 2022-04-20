#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		if(n<m)swap(n,m);
		if((n==1 and m>=3) or (m==1 and n>=3)){
			cout<<"-1\n";
			continue;
		}
		//if()
		if((n+m)%2==1){
			int ans=2*m-2+(n-m-1)*2+1;
			cout<<ans<<'\n';
			continue;
		}
		if((n+m)%2==0){
			int ans=2*m-2+(n-m-1)*2+1+1;
			cout<<ans<<'\n';
			continue;
		}


	}
	return 0;
}