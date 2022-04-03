#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long

const int mod=1e9+7;
const int maxn=2e5+7;

ll fa[maxn];

ll qpow(ll a,ll b,ll mod){//a^b
    ll ans=1,base=a;
    while(b){
        if(b&1) ans=ans*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ans;
}

void init(){
	fa[0]=fa[1]=1;//f[0]也要赋值
	FOR(i,2,maxn-1)
		fa[i]=fa[i-1]*i%mod;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	init();
	int T;cin>>T;
	while(T--){
		ll n,m,k,q;
		cin>>n>>m>>k>>q;
		if(n-k<0){cout<<"0\n";continue;}
		ll A=fa[n]*fa[n+m-k]%mod;
		ll B=fa[n-k]*fa[n+m]%mod;
		B=qpow(B,mod-2,mod);//B转换为逆元
		ll ans=qpow(A*B%mod,q,mod);
		cout<<ans<<'\n';
	}
	return 0;
}