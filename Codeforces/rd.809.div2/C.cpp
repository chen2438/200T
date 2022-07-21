#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define int long long
const int N = 1e5+7;
int a[N],pre[N],suf[N];

void solve(){
    memset(pre,0,sizeof pre);
    memset(suf,0,sizeof suf);
    int n; cin>>n;
    FOR(i,1,n) cin>>a[i];
    
    for(int i=2;i<=n-1;i+=2)
        pre[i] += max({0ll,a[i-1]+1-a[i],a[i+1]+1-a[i]});
    FOR(i,1,n) pre[i]=pre[i]+pre[i-1];
    
    if(n%2==1) {cout<<pre[n]<<endl;return;}
    
    for(int i=3;i<=n-1;i+=2)
        suf[i] += max({0ll,a[i-1]+1-a[i],a[i+1]+1-a[i]});
    ROF(i,n,1) suf[i]=suf[i]+suf[i+1];
    
    int pos,min0=1e18;
    FOR(i,1,n) min0=min(min0,pre[i]+suf[i+1]);
    cout<<min0<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}