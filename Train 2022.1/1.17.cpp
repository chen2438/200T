#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a));
using namespace std;
int dp[207][207],v[207];
int main(){
	int n,i,j,k,ans=0;
	cin>>n;
	FOR(i,1,n){
		cin>>v[i];
		v[i+n]=v[i];
	}
	FOR(i,1,2*n)
		ROF(j,i-1,1)
			FOR(k,j,i-1)
				dp[j][i]=max(dp[j][i],v[j]*v[k+1]*v[i+1]+dp[j][k]+dp[k+1][i]);
	FOR(i,1,n)
		ans=max(ans,dp[i][i+n-1]);
	cout<<ans<<endl;
}
