#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long

const int mod=1e9+7;

ll qpow(ll a,ll b,ll mod){//a^b
    ll ans=1,base=a;
    while(b){
        if(b&1) ans=ans*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ans;
}

ll C(ll n,ll m,ll p){
    if(n<m) return 0;
    if(m>n-m) m=n-m;
    ll a=1,b=1;
    FOR(i,0,m-1){
        a=(a*(n-i))%p;
        b=(b*(i+1))%p;
    }
    return a*qpow(b,p-2,p)%p;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		ll n,m,k,q;
		cin>>n>>m>>k>>q;
		ll A=C(n,k,mod);
		ll B=C(n+m,k,mod);
		B=qpow(B,mod-2,mod);
		ll ans=qpow(A*B%mod,q,mod);
		cout<<ans<<'\n';
	}
	return 0;
}