#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int x[107],n;

bool go_on(){
	sort(x+1,x+n+1);
	FOR(i,1,n) cout<<x[i]<<" ";
	cout<<endl;
	FOR(i,2,n) if(x[i-1]!=x[i]) return true;
	return false;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	FOR(i,1,n) cin>>x[i];
	while(go_on()){
		int mindif=1e9, pos=0;
		FOR(i,2,n){
		    if(x[i]-x[i-1]==0) continue;
			if(x[i]-x[i-1]<mindif){
				pos=i;
				mindif=x[i]-x[i-1];
			}
		}
		x[pos]-=x[pos-1];
	}
	cout<<n*x[1]<<endl;
	return 0;
}

