#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;


#define int long long
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		//if(n==1) cout<<0<<endl;
		ROF(i,10,0) {
			int dif=1;
			FOR(j,1,i) dif*=10;
			if(n-dif>=0){
				cout<<n-dif<<endl;
				break;
			}
		}
	}
	return 0;
}