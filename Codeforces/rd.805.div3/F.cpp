#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

int a[200007],b[200007];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		FOR(i,1,n) cin>>a[i];
		FOR(i,1,n) cin>>b[i];
		FOR(i,1,n){
			while(a[i]%2==0) a[i]/=2;
			while(b[i]%2==0) b[i]/=2;
		}
		multiset<int> A(a+1,a+n+1);
		multiset<int> B(b+1,b+n+1);
		for(auto i:B){
			auto it=A.find(i);
			if(it!=A.end())A.erase(it);
			else{
				while(1){
					i/=2;
					if(i==0){break;}
					auto jt=A.find(i);
					if(jt!=A.end()){A.erase(jt);break;}
				}
			}
		}
		if(A.size()==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}