#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

int matx[107][107];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		mem(matx);
		FOR(i,1,n){
			FOR(j,1,n){
				char c;cin>>c;
				if(c=='1') matx[i][j]=1;
			}
		}
		int ans=0;
		FOR(i,1,n){
			FOR(j,1,n){
				int sum=matx[i][j]+matx[j][n-i+1]+matx[n-j+1][i]+matx[n-i+1][n-j+1];
				ans+=min(4-sum,sum);
				if(sum>=2){
					matx[i][j]=matx[j][n-i+1]=matx[n-j+1][i]=matx[n-i+1][n-j+1]=1;
				}
				else{
					matx[i][j]=matx[j][n-i+1]=matx[n-j+1][i]=matx[n-i+1][n-j+1]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}