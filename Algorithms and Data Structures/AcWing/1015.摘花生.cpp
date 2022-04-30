//web:https://www.acwing.com/problem/content/1017/
//begin:4.30 09:50
//end:4.30 10:06
//judge:AC
//optimize:yes
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int INF=(1<<30);
int a[507][507],dp[507][507];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int R,C;
		cin>>R>>C;
		/*FOR(i,0,R){
			FOR(j,0,C){
				dp[i][j]=a[i][j]=-INF;
			}
		}*/
		FOR(i,1,R){
			FOR(j,1,C){
				cin>>a[i][j];
			}
		}
		//dp[1][1]=a[1][1];
		FOR(i,1,R){
			FOR(j,1,C){
				//if(i==1 and j==1)continue;
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
			}
		}
		cout<<dp[R][C]<<endl;
	}
	return 0;
}