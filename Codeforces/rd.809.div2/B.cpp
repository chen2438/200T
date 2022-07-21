#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

//#define int long long
const int N = 1e5+7;
vector<int> p[N];

void solve(){
    int n; cin>>n;
    FOR(i,1,n) p[i].clear();
    FOR(i,1,n){
        int x; cin>>x;
        p[x].push_back(i);
    }
    FOR(i,1,n){
        if(p[i].empty()) {cout<<0<<" "; continue;}
        int cnt=1,pre=p[i][0];
        FOR(j,1,p[i].size()-1){
            if((p[i][j]-pre)%2==1){
                cnt++;
                pre=p[i][j];
            }
        }
        cout<<cnt<<" ";
    }
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}