#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

int a[107];

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		mem(a);
		FOR(i,1,n){
			cin>>a[i];
		}
		int l=1,r=n;
		while(a[l+1] and l<r){
			l++;
		}
		while(a[r-1] and l<r){
			r--;
		}
		cout<<r-l<<'\n';
	}
	return 0;
}