#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;

const int N=1e6+5;
const int M=2;
const int mod=998244353;

int val[N];
ll f[N][M];
vector<int>res[N];

ll solve(vector<int>ans){
	int n=ans.size();
	if(n==1) return 0;
	f[1][1]=ans[0]+ans[1];
	f[1][0]=0;
	FOR(i,2,n-1){
		f[i][1]=max(f[i-2][0],f[i-2][1])+ans[i]+ans[i-1];
		f[i][0]=max(f[i-1][1],f[i-1][0]);
	}
	ll res=0;
	res=max(res,max(f[n-1][0],f[n-1][1]));
	FOR(i,0,n-1)
		f[i][0]=f[i][1]=0;
	return res;
}

void run(){
	int n,k;
	cin>>n>>k;
    FOR(i,1,n)
    	cin>>val[i];
	FOR(i,1,k){
		for(int j=i;j<=n;j+=k)
			res[i].push_back(val[j]);
	}
	ll ans=0;
	FOR(i,1,k)
		ans+=solve(res[i]);
	cout<<ans<<'\n';
}

int main(){
	run();
	return 0;
}