#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int maxn=2e5+7;
//int a[maxn];
multiset<int> ms;


signed main(){
	int t;
	cin>>t;
	while(t--){
		ms.clear();
		int n,k,o;
		cin>>n>>k;
		FOR(i,1,n){
			//cin>>a[i];
			cin>>o;
			ms.insert(o);
		}
		int x,y,ans=0;
		while(!ms.empty()){
			auto it=ms.begin();
			x=*it;
			ms.erase(it);
			it=ms.find(x*k);
			if(it==ms.end()){
				ans++;
			}
			else{
				ms.erase(it);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}