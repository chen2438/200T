#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int N = 1007;
char ans[N][N];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	int sum=0;
	FOR(i,1,n){
		FOR(j,1,n){
			if(i%2+j%2==2 or i%2+j%2==0) ans[i][j]='C',sum++;
			if(i%2+j%2==1) ans[i][j]='.';
		}
	}
	cout<<sum<<endl;
	FOR(i,1,n){
		FOR(j,1,n) cout<<ans[i][j];
		cout<<endl;
	}
	return 0;
}