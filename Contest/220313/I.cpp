#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long
#define int long long

const int mod=100000007;
ll n,m;

ll q_mul(ll a,ll b){
    ll ans=0;
    while(b){
        if(b&1){
            b--;
            ans=(ans+a)%mod;
        }
        b>>=1;
        a=(a+a)%mod;
    }
    return ans%mod;
}

ll A(ll n){
    ll ans=1;
    FOR(i,1,n){
        ans=q_mul(ans,i);
    }
    return ans;
}

signed main(){
    cin>>n>>m;
    ll ans=q_mul(A(m-1),A(n-1));
    ans=q_mul(ans,q_mul(n-1,n-2)+2);
    cout<<ans<<'\n';
    return 0;
}
