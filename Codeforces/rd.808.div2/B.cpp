#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int N = 1e5+7;
int a[N];

void solve(){
    memset(a,0,sizeof a);
    int n,l,r; cin>>n>>l>>r;
    int ans=1;
    FOR(i,1,n){
        if(l%i==0) a[i]=l;
        else if(r%i==0) a[i]=r;
        else{
            int k1=l/i,k2=r/i;
            if(k1==k2) {ans=0;break;}
            a[i]=i*k2;
        }
    }
    if(ans==0){cout<<"NO\n";return;}
    cout<<"YES\n";
    FOR(i,1,n) cout<<a[i]<<" ";
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}