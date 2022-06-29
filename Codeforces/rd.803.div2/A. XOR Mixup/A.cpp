#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int a[1000];

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int sum=0;
		FOR(i,1,n){
			cin>>a[i];
			sum^=a[i];
		}
		FOR(i,1,n){
			if((sum ^ a[i]) == a[i]){
				cout<<a[i]<<'\n';
				break;
			}
		}
	}
	return 0;
}