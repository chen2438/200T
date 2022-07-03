#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int N = 1e5+7;
int b[N],ans[N];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	FOR(i,1,n) cin>>b[i];
	sort(b+1,b+n+1);
	int pos=1;
	FOR(i,1,n){
		if(ans[pos-1]<b[i]){
			ans[pos]=b[i];
			b[i]=0;
			pos++;
		}
	}
	sort(b+1,b+n+1,greater<int>());
	FOR(i,1,n){
		if(b[i]==0) break;
		if(ans[pos-1]>b[i]){
			ans[pos]=b[i];
			b[i]=0;
			pos++;
		}
	}
	cout<<pos-1<<endl;
	FOR(i,1,pos-1) cout<<ans[i]<<' ';
	return 0;
}