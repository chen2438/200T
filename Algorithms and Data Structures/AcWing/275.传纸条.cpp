//web:https://www.acwing.com/problem/content/description/277/
//begin:4.30 16:54
//end:4.30 
//judge:AC
//optimize:yes
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int INF=(1<<30);
const int maxn=57;
int a[maxn][maxn],dp[maxn*2][maxn][maxn];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m;cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>a[i][j];
		}
	}

	FOR(k,2,n+m){
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