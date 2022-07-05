#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long
int a[N];
const int N = 1e5+7;
const int p = 1e9+7;

ll fact[N];

void InitFact(){
	fact[0]=1;
	FOR(i,1,N){
		fact[i]=fact[i-1]*i%p;
	}
}

ll qpow(ll a,ll b,ll p){
    ll ans=1,base=a;
    while(b){
        if(b&1) ans*=base,ans%=p;
        base*=base,base%=p;
        b>>=1;
    }
    return ans;
}

ll A(ll n,ll m,ll p){
    return fact[n]*qpow(fact[n-m],p-2,p);
}

ll C(ll n,ll m,ll p){
    return fact[n]*qpow(fact[m],p-2,p)%p*qpow(fact[n-m],p-2,p)%p;
}

signed main(){
	InitFact();
	cout<<A(3,3,p);
	return 0;
}

signed tmain(){
	cin.tie(0)->sync_with_stdio(0);
	InitFact();
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		memset(a,0,sizeof a);
		FOR(i,1,n) cin>>a[i];
		int p0;
		FOR(i,1,n) if(a[i]==0)
	}
	return 0;
}