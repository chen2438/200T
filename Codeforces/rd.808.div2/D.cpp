#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int N = 1e5+7;
vector<int> a(N),b(N);

void solve(){
    int n; cin>>n;
    FOR(i,1,n) cin>>a[i];
    int l1=0,l2=0;
    while(l1<n-1){
        sort(a.begin()+l1,a.begin()+n+1);
        if(a[n]==0) break;
        FOR(i,l1,n-1){
            if(a[i]!=0) break;
            if(a[i+1]!=0){l1=i;break;}
        }
        l2++;
        l1=max(l1,l2);
        ROF(i,n,l1+1) a[i]=a[i]-a[i-1];
        a[l1]=0;
    }
    cout<<a[n]<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}