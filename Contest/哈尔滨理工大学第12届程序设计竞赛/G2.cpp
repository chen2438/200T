#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,m;cin>>n>>m;
		long long ans=0;
		while(n!=0 and m!=0){
			if(n<m)swap(n,m);
			int t=n/m;
			ans+=t;
			n-=t*m;
		}
		cout<<ans<<'\n';

	}
	return 0;
}