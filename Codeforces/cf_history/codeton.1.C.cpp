#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int maxn=1e5+7;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> a(maxn,0);
		int op=-1;
		FOR(i,1,n){
			cin>>a[i];
			if(a[i]==1) op=1;
		}
		if(op==-1){cout<<"YES\n";continue;}
		sort(a.begin()+1,a.begin()+n+1);
		if(a[1]==0){cout<<"NO\n";continue;}
		int f=1;
		FOR(i,1,n){
			if(a[i]>2)break;
			if(a[i]==2){
				f=0;
				break;
			}
		}
		if(f==0){cout<<"NO\n";continue;}
		f=1;
		FOR(i,1,n-1){
			if(a[i]+1==a[i+1]){
				f=0;
				break;
			}
		}
		if(f==0){cout<<"NO\n";continue;}
		else{cout<<"YES\n";continue;}
	}
	return 0;
}