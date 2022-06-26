#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset(a,0,sizeof(a))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define scan(a) scanf("%d",&(a))
using namespace std;

const int maxn=1e5+7;
int a[maxn];
//priority_queue<int,vector<int>,greater<int>> pq;

int main(){
	int t;cin>>t;
	while(t--){
		int n;scan(n);
		long long sum=0;
		int o,max0=-1;
		FOR(i,1,n){
			scan(o);
			sum+=o;
			max0=maxs(o,max0);
		}
		if(sum==0){
			cout<<0<<'\n';
			continue;
		}
		if(sum-max0>=max0-1){
			cout<<1<<'\n';
		}
		else{
			cout<<max0-(sum-max0)<<'\n';
		}

	}
	return 0;
}