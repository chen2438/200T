#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

int x[107],n;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	int ans=0,cnt=0;
	FOR(i,1,n) cin>>x[i];
	sort(x+1,x+1+n);
	while(cnt<n){
		int size=0;
		FOR(i,1,n){
			if(x[i]==-1)continue;
			if(x[i]>=size){
				size++;
				cnt++;
				x[i]=-1;
				continue;
			}
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}


