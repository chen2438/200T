//web:https://www.acwing.com/problem/content/1029/
//begin:4.30 13:16
//end:4.30 13:58
//judge:AC
//optimize:yes
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int INF=(1<<30);
int a[15][15],dp[30][15][15];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	int x,y,v;
	while(cin>>x>>y>>v,x or y or v) a[x][y]=v;

	FOR(k,2,2*n){
		FOR(i1,1,n){
			FOR(i2,1,n){
				int j1=k-i1,j2=k-i2,w;
				if(j1>=1 and j1<=n and j2>=1 and j2<=n){
					if(i1==i2) w=a[i1][j1];
					else w=a[i1][j1]+a[i2][j2];

					dp[k][i1][i2]=max({dp[k-1][i1-1][i2],dp[k-1][i1][i2-1],
									dp[k-1][i1-1][i2-1],dp[k-1][i1][i2]}) + w;

				}
			}
		}
	}
	cout<<dp[2*n][n][n];
	return 0;
}