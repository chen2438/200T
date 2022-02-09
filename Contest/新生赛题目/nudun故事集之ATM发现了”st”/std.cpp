#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
ll ans[65][N],n,m,x[N],s[64];
int main(){
	//freopen("13.in","r",stdin);
	//freopen("13.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	while(m--){
		ll l,r,w;
		scanf("%lld%lld%lld",&l,&r,&w);
		for(int i=63;i>=0;i--){
			if(w&(1ll<<i))continue;
			ans[i][l]++;ans[i][r+1]--;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=63;j>=0;j--){
			s[j]+=ans[j][i];
			if(s[j]<=0)continue;
			if((x[i]&(1ll<<j)))x[i]=(x[i]^(1ll<<j));
		}
		printf("%lld ",x[i]);
	}
}
