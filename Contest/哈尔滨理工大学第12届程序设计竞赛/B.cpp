#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long
//#define __gcd gcd;

const int mod=1e9+7;
const int maxn=1e5+7;

ll quick_pow(ll a,ll b,ll mod){//a^b%mod
    ll ans=1,base=a;
    while(b){
        if(b&1) ans*=base,ans%=mod;
        base*=base,base%=mod;
        b>>=1;
    }
    return ans;
}

ll qpow(ll a,ll b){//a^b
    ll ans=1,base=a;
    while(b){
        if(b&1) ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		ll n,m,k,q;
		cin>>n>>m>>k>>q;
		ll A=1,B=1;
		FOR(i,0,k-1){
			A*=n-i;
			B*=n+m-i;
		}
		A=qpow(A,q);
		B=qpow(B,q);
		ll ans=A*quick_pow(B,mod-2,mod)%mod;
		//ans=ans*A%mod;
		cout<<ans<<'\n';
	}
	return 0;
}