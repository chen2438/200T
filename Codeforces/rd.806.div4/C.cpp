#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

#define int long long

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int ed[1000];
		mem(ed);
		FOR(i,1,n){
			cin>>ed[i];
		}
		string op[1000];
		//mem(op);
		FOR(i,1,n){
			int len;cin>>len;
			cin>>op[i];
			for(auto j:op[i]){
				if(j=='U') ed[i]--;
				if(j=='D') ed[i]++;
				if(ed[i]>9)ed[i]-=10;
				if(ed[i]<0)ed[i]+=10;
			}
		}
		FOR(i,1,n){
			cout<<ed[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}