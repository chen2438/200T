#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define int long long
using namespace std;

const int N=1e4+5,M=1e7+5;
int n,m,w[N],val[N],dp[M];

signed main(){
	cin>>m>>n;
	FOR(i,1,n)
		cin>>w[i]>>val[i];
	FOR(i,1,n){
		FOR(j,w[i],m){
			dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
		}
	}
	cout<<dp[m];
	return 0;
}