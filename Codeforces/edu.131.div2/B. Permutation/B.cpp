#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

vector<int> a;
array<int,200007> vst;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		a.clear();
		vst.fill(0);
		int n;cin>>n;
		FOR(i,1,n){
			if(vst[i]) continue;
			for(int j=i;j<=n and !vst[j];j*=2){
				vst[j]=1;
				a.push_back(j);
			}
		}
		cout<<2<<endl;
		for(auto i:a) cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}