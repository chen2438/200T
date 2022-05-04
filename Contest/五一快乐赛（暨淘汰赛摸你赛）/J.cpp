#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int a[20],b[20];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	FOR(i,1,12){
		cin>>a[i];
	}
	FOR(i,1,12){
		b[i]=b[i-1]+a[i];
	}
	int max0=-1e9,ans=0;
	FOR(i,1,12){
		if(max0<=b[i]){
			max0=b[i];
			ans=i;
		}
	}
	cout<<ans;


}