#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
multiset<string> ms;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;

	FOR(i,1,n){
		string st;cin>>st;
		ms.insert(st);
		cout<<ms.count(st)-1<<'\n';
	}


}