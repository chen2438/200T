#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

long long a[1007];

long long ans[3];

void game(int l,int r,int player){
	if(l==r) {ans[player]+=a[l];return ;}
	if(a[l]<a[r]) {ans[player]+=a[r];r--;}
	else {ans[player]+=a[l];l++;}
	game(l,r,player^1);
}

signed main(){
	//freopen("in.txt","r",stdin);
	//cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	FOR(i,1,n) cin>>a[i];
	game(1,n,0);
	cout<<ans[0]<<' '<<ans[1]<<endl;
	return 0;
}