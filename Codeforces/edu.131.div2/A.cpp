#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int a[3][3];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int sum=0;
		FOR(i,1,2){
			FOR(j,1,2){
				cin>>a[i][j];
				sum+=a[i][j];
			}
		}
		if(sum==0)cout<<0<<endl;
		if(sum>=1 and sum<=3)cout<<1<<endl;
		if(sum==4)cout<<2<<endl;
	}
	return 0;
}