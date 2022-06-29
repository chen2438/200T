#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

vector<int> neg,pos,sum;

bool judge(){
	int len=sum.size();
	int ans=0;
	FOR(i,0,len-1){
		FOR(j,i+1,len-1){
			FOR(k,j+1,len-1){
				ans=0;
				FOR(l,0,len-1) if(sum[i]+sum[j]+sum[k]==sum[l]) ans=1;
				if(ans==0) return false;
			}
		}
	}
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		neg.clear();pos.clear();sum.clear();
		int n;cin>>n;
		int zero=0;
		FOR(i,1,n){
			int x;cin>>x;
			if(x<0) neg.push_back(x);
			if(x==0) zero++;
			if(x>0) pos.push_back(x);
		}
		if(neg.size()>2 or pos.size()>2) {cout<<"NO\n";continue;}
		if(zero>2) zero=2;
		for(auto i:neg) sum.push_back(i);
		for(auto i:pos) sum.push_back(i);
		FOR(i,1,zero) sum.push_back(0);
		if(judge()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}