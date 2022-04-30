//web:https://www.acwing.com/problem/content/description/900/
//begin:4.30 09:33
//end:4.30 09:43
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int INF=(1<<30);
int a[507][507],dp[507][507];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	FOR(i,0,n){
		FOR(j,0,n){
			dp[i][j]=a[i][j]=-INF;
		}
	}
	FOR(i,1,n){
		FOR(j,1,i){
			cin>>a[i][j];
		}
	}
	dp[1][1]=a[1][1];
	FOR(i,2,n){
		FOR(j,1,i){
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
		}
	}
	int sum=-INF;
	FOR(i,1,n){
		sum=max(sum,dp[n][i]);
	}
	cout<<sum<<endl;
	return 0;
}