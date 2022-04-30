#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int maxn = 1e5+7;
int V[maxn],W[maxn];
int dp[4007][4007];
int v,w,n;
void solve(){
	dp[0][0]=0; 
	FOR(i,1,n){
		ROF(j,v,0){
			ROF(k,w,0){
				int t1=j+V[i],t2=k+W[i];
				dp[t1][t2]=max(dp[j][k]+1,dp[t1][t2]);
			}
		}
	}
	cout<<dp[v][w]<<'\n';
}
int main(){
	cin>>n>>v>>w;
	FOR(i,1,n){
		cin>>V[i]>>W[i];
	}
	solve();
	return 0;
}