#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define int long long
using namespace std;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
      int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &X:a) cin>>X;
    for(auto &X:b) cin>>X;

    int ans = 0;
    FOR(i,1,n-1){
      ans += min(abs(a[i]-a[i-1])+abs(b[i]-b[i-1]), 
                 abs(a[i]-b[i-1])+abs(b[i]-a[i-1]));
    }
    cout<<ans<<'\n';
  }
  return 0;
}