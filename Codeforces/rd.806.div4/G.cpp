#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
<<<<<<< Updated upstream
const int N = 1e5+7;
int a[N],pre[N];

void solve(){
	int n,k;
	cin>>n>>k;
	FOR(i,1,n){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	int ans=-1e9,sum=0;
	FOR(i,0,n){
		sum = -i*k;
		sum += pre[i];
		FOR(j,i+1,n){
			if(j-i-1>32)break;
			sum += a[j]>>(j-i);
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
=======

int a[100007];

void solve(){
	int n,k; cin>>n>>k;
	FOR(i,1,n) cin>>a[i];
	
>>>>>>> Stashed changes
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
    while(T--){
        solve();
    }
	return 0;
}