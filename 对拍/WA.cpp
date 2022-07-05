#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long

const int N = 1e5+7;
const int p = 1e9+7;

int a[N];
int cnt[N];
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
	cin.tie(0)->sync_with_stdio(0);
	InitFact();
	int T;cin>>T;
	FOR(_i,1,T){

		int n;cin>>n;
		memset(a,0,sizeof a);
		FOR(i,1,n) cin>>a[i];
		int p0;
		FOR(i,1,n) if(a[i]==0) p0=i;

		memset(cnt,0,sizeof cnt);
		FOR(i,1,p0) cnt[a[i]]=1;
		int mexl;
		FOR(i,0,n-1) if(cnt[i]==0) {mexl=i;break;}
		int greaterl=0,lessl=0;
		FOR(i,2,p0-1){
			if(a[i]>mexl) greaterl++;
			if(a[i]<mexl) lessl++;
		}
		ll ansl=C(greaterl+lessl,lessl,p)*fact[lessl]%p;
		if(ansl==0) ansl=1;

		memset(cnt,0,sizeof cnt);
		FOR(i,p0,n) cnt[a[i]]=1;
		int mexr;
		FOR(i,0,n-1) if(cnt[i]==0) {mexr=i;break;}
		int greaterr=0,lessr=0;
		FOR(i,p0+1,n-1){
			if(a[i]>mexl) greaterr++;
			if(a[i]<mexl) lessr++;
		}
		ll ansr=C(greaterr+lessr,lessr,p)*fact[lessr]%p;
		if(ansr==0) ansr=1;
		ll ans=ansl*ansr%p*fact[greaterl+greaterr]%p;
		if(ans==0) ans=1;
		//if(ans==1) continue;
		//FOR(i,1,n) cout<<a[i]<<" ";
		//cout<<"ans=";
		cout<<ans<<endl;

	}
	return 0;
}