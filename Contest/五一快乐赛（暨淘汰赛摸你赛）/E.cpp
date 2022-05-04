
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
#define int long long
using namespace std;

const int INF=(1<<30);
int a[507][507],dp[507][507];

signed main(){
	cin.tie(0)->sync_with_stdio(0);

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
		dp[1][1]=1;
		FOR(i,1,R){
			FOR(j,1,C){
				//if(i==1 and j==1)continue;
				if(a[i][j]>=a[i-1][j]){
					dp[i][j]+=dp[i-1][j];
				}
				if(a[i][j]>=a[i][j-1]){
					dp[i][j]+=dp[i][j-1];
				}
				//dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
			}
		}
		int ans,x=1,y=1;
		FOR(i,1,R){
			FOR(j,1,C){
				if(dp[i][j]>0){
					if(x*x+y*y<i*i+j*j or (x*x+y*y==i*i+j*j and x>i)){
						ans=dp[i][j];
						x=i;
						y=j;
					}

				}
			}
		}
		cout<<x<<" "<<y<<endl;
		cout<<ans<<endl;
	return 0;
}