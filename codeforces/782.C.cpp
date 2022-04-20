#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl "\n"
const ll inf=1e18+7;
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
	    int n;
	    ll a,b;
	    cin>>n>>a>>b;
	    vector<ll> x(n+1),p(n+1);
	    x[0]=0;
	    for(int i=1;i<=n;i++) cin>>x[i];
	    partial_sum(x.begin(),x.end(),p.begin());
	    ll ans=inf;
	    for(int i=0;i<=n;i++)
	        ans=min(ans,(a+b)*(x[i]-x[0])+b*(p[n]-p[i]-(n-i)*x[i]));
	    cout<<ans<<endl;
	}
	return 0;
}