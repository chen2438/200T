#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int maxn=2e5+7;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		k=abs(k);
		vector<int> a(maxn,0);
		FOR(i,1,n){
			cin>>a[i];
		}
		sort(a.begin()+1,a.begin()+n+1);
		multiset<int> b(a.begin()+1,a.begin()+n+1);
		if(a[n]-a[1]<k){cout<<"NO\n";continue;}
		int f=0;
		FOR(i,1,n){
			auto it=b.find(a[i]+k);

			if(it!=b.end()){//a[pos]==a[i]+k
				//cout<<"i="<<i<<",*it="<<*it<<endl;
				f=1;
				break;
			}
			
		}
		if(f)cout<<"YES\n";
		else cout<<"NO\n";


	}
	return 0;
}