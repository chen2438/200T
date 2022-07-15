#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
int a[200007];

void solve(){
	int n;cin>>n;
	priority_queue<int,vector<int> , greater<>> b;
	FOR(i,1,n) {
		cin>>a[i];
		if(a[i]>0) b.push(i);
	}
	if(b.size()==0) {cout<<0<<endl;return;}
	int ans=0;
	int _i=1;
	while(a[_i]==0)_i++;
	FOR(i,_i,n){
	    
		if(a[i]==0){
			int t=b.top();b.pop();
			a[i]=1;
			a[t]--;
			ans++;
			b.push(i);
			if(a[t]>0) b.push(t);
// 			FOR(j,1,n) cout<<a[j]<<" ";
// 		cout<<endl;
		}
		
	}
	while(b.size()>1){
		int t=b.top();b.pop();
		ans+=a[t];
	}
	cout<<ans<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
    while(T--){
        solve();
    }
	return 0;
}