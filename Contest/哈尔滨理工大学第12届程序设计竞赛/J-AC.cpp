#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
using namespace std;

const int maxn=1e6+7;

ll qpow(ll a,ll b,ll p){//a^b%p
    ll ans=1,base=a;
    while(b){
        if(b&1) ans*=base,ans%=p;
        base*=base,base%=p;
        b>>=1;
    }
    return ans;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		ll x,p;
		string y;
		vector<ll> pre(maxn,0);
		cin>>x>>y>>p;
		reverse(y.begin(),y.end());
		int len=y.size();
		pre[0]=x%p;
		FOR(i,1,len-1)
			pre[i]=qpow(pre[i-1],10,p);
		ll ans=1;
		FOR(i,0,len-1)
			ans=ans*qpow(pre[i],y[i]-'0',p)%p;
		cout<<ans<<'\n';
	}
	return 0;
}