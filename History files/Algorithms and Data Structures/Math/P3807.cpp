#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;
using namespace std;

ll qpow(ll a,ll b,ll p){//a^b%p
    ll ans=1,base=a;
    while(b){
        if(b&1) ans*=base,ans%=p;
        base*=base,base%=p;
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

ll Lucas(ll n,ll m,ll p){
	if(m==0) return 1;
	return Lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}

int main(){
	int T;cin>>T;
	while(T--){
		ll n,m,p;
		cin>>n>>m>>p;
		cout<<Lucas(n+m,m,p)%p<<endl;
	}
	return 0;
}