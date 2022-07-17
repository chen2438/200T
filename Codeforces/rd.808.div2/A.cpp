#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int N = 107;
int a[N];

void solve(){
    int n;cin>>n;
    FOR(i,1,n) cin>>a[i];
    int ans=1;
    FOR(i,2,n) if(a[i]%a[1]!=0){ans=0;break;}
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}