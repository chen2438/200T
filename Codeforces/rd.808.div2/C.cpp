#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int N = 1e5+7;
int a[N];
int ans[N],qmin[N];

void solve(){
    mem(a),mem(qmin),mem(ans);
    int n,q; cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    qmin[n]=1;
    ROF(i,n-1,1){
        if(a[i]<=qmin[i+1]) qmin[i]=qmin[i+1];
        else qmin[i]=qmin[i+1]+1;
    }
    FOR(i,1,n){
        if(qmin[i]<=q){
            FOR(j,i,n) ans[j]=1;
            break;
        }
        else if(a[i]<=q) ans[i]=1;
        else ans[i]=0;
    }
    FOR(i,1,n) cout<<ans[i];
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}