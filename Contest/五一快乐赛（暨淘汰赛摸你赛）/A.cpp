#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;cin>>s;
	string s0="zstu";
	int j=0;
	FOR(i,0,s.size()-1){
		if(s[i]==s0[j])j++;
		if(j==4)break;
	}
	if(j==4)cout<<"yes";
	else cout<<"no";
	return 0;
}