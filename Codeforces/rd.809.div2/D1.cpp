#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

//#define int long long
const int N = 1e5+7;
int a[N];

void solve(){
    int n,k; cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    if(n==1) {cout<<0<<endl;return ;}
    if(k>a[n]) {cout<<0<<endl;return ;}
    int ans=2e9;
    FOR(i,a[n]/k,a[n]/1){
        int cmin=1e9;
        FOR(j,1,n){
            int l=1, r=k;
            while(l<r){
                int mid=(l+r)/2;
                if(a[j]/mid<=i) r=mid;
                else l=mid+1;
            }
            if(a[j]/r>i) {cmin=-1e9;break;}
            cmin=min(cmin,a[j]/r);
        }
        ans=min(ans,i-cmin);
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}