#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int a[int(1e5+7)];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	float w,h;
	cin>>n>>w>>h;
	w=sqrt(w*w+h*h)+1e-8;
	FOR(i,1,n){
		float _t;
		cin>>_t;
		if(_t<=w)cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}