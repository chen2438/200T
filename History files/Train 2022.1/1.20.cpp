#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
#define FOR(i,a,b) for(register int i=(a);i<=(b);i++)
#define lock _lock
const int INF (1<<30);
using namespace std;

int lock[1010],data[1010],dp1[110][110],dp[110][110];
int n,ans,tot,ma;
void init(){
	cin>>n>>data[1];
	for(int i=1;i<=n;i++){
		lock[i]=data[i]%100;
		data[i+1]=(data[i]*6807+2831)%201701;
	}
}
int check(int i,int j){
	int mi=min4(100,abs(lock[i]-j),abs(lock[i]+100-j),abs(j+100-lock[i]));
	return mi*mi;
}
int main(){
	int i,j,k,ans=INF;
	init();

	for(i=1;i<=n;++i){
		for(j=0;j<=99;++j){
			dp[i][j]=INF;
			dp1[i][j]=check(i,j);
		}
	}
	for(j=0;j<=99;++j)
		dp[1][j]=dp1[1][j];//³õÊ¼Ìõ¼þ 
	for(i=2;i<=n;++i)
		for(j=0;j<=99;++j)
			for(k=0;k<j;++k)
				dp[i][j]=min(dp[i][j],dp[i-1][k]+dp1[i][j]);
	for(j=0;j<=99;++j)
		ans=min(ans,dp[n][j]);
	cout<<ans;
	return 0;
}

