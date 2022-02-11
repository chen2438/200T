#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

#define map _map
const int maxn=1e5+7;
int a2[maxn],dp[maxn],map[maxn];

int main() {
	int n;cin>>n;
	int x;
	FOR(i,1,n){
		cin>>x;//x=a1[i]
		map[x]=i;//a1[i] -> i
	}
	FOR(i,1,n){
		cin>>x;
		a2[i]=map[x];
	}

	int len=1;
	dp[1]=a2[1];

	FOR(i,2,n){
		if(dp[len]<=a2[i]) dp[++len]=a2[i];
		else{
			int p1=upper_bound(dp+1,dp+1+len,a2[i],less<int>())-dp;
			dp[p1]=a2[i]; 
		}
	}
	cout<<len;
	return 0;
}