#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

//#define int long long
const int N = 1e5+7;
int a[N];
char s[N];

void solve(){
    int n,m; cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,m) s[i]='B';
    FOR(i,1,n){
        int l=a[i], r=m+1-a[i];
        if(r<l) swap(l,r);
        if(s[l]=='B') s[l]='A';
        else s[r]='A';
    }
    FOR(i,1,m) cout<<s[i];
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}