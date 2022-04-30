//web:https://www.acwing.com/problem/content/1020/
//begin:4.30 10:28
//end:4.30 10:33
//judge:AC
//optimize:no
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int INF=(1<<30);
int a[507][507],dp[507][507];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	while(T--){
		int n;
		cin>>n;
		FOR(i,0,n){
			FOR(j,0,n){
				dp[i][j]=a[i][j]=INF;
			}
		}
		FOR(i,1,n){
			FOR(j,1,n){
				cin>>a[i][j];
			}
		}
		dp[1][1]=a[1][1];
		FOR(i,1,n){
			FOR(j,1,n){
				if(i==1 and j==1)continue;
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
			}
		}
		cout<<dp[n][n]<<endl;
	}
	return 0;
}