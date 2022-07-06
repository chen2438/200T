#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int N = 2e5+7;
int n,m;
double v[N],pre[N];

double MinTime(){
	double ans=0;
	FOR(i,1,n){
		ans=max(ans,pre[i]/(1.0*i));
	}
	return ans;
}//为了填满第i个水库, 必须消耗pre[i]/i的时间
//填满所有水库所需要的最小时间取决于最大的pre[i]/i
//木桶效应

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	FOR(i,1,n){
		cin>>v[i];
		pre[i]=pre[i-1]+v[i];
	}
	double mt=MinTime();
	cin>>m;
	while(m--){
		int t;cin>>t;
		if(t<mt) {cout<<-1<<endl;continue;}
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(pre[n]/(mid*1.0)<=t) r=mid;
			else l=mid+1; 
		}
		cout<<r<<endl;
	}
	return 0;
}