#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define maxn 30007
int a[maxn],b[maxn];

signed main(){
	FOR(i,1,maxn-1){
		a[i]=i;
	}
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		FOR(i,1,n){
			cin>>a[i];
		}
		int sum=a[1];
		FOR(i,2,n){
			sum=sum^a[i];
		}
		FOR(i,1,n){
			if((sum|a[i]) == a[i]){
				cout<<a[i]<<'\n';
				break;
			}
		}
	}
	return 0;
}