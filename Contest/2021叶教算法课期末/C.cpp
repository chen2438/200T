#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int a[int(1e5+7)];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[1]<<' '<<a[n];
	return 0;
}