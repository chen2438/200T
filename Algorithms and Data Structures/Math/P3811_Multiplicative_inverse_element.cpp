//#pragma GCC optimize(2)
//std::ios::sync_with_stdio(0)
//clock_t st=clock();
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

#define ll long long 
ll n,mod;

ll quick_pow(ll a,ll b){//a^b
    ll ans=1,base=a;
    while(b){
        if(b&1) ans*=base,ans%=mod;
        base*=base,base%=mod;
        b>>=1;
    }
    return ans;
}

int main(){
    cin>>n>>mod;
    FOR(i,1,n){
        ll ans=quick_pow(i,mod-2)%mod;
        printf("%lld\n",ans);
    }
    
    return 0;
}