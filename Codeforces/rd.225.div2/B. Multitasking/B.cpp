#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int n,m,t;
	cin>>n>>m>>t;
	cout<<m*(m-1)/2<<endl;
	FOR(i,1,m){
		FOR(j,i+1,m){
			if(t) cout<<j<<" "<<i<<endl;
			else cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}