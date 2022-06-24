#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define mem(a) memset((a),0,sizeof(a))
#define int long long
const int INF=LLONG_MAX;
const int maxn=5e5+7;
int presum[maxn],vst[maxn];

int sum(int l,int r){
	return presum[r]-presum[l-1];
}

struct node{
	int num,val;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		mem(vst);
		mem(presum);
		vector<node> pt(maxn);
		vector<int> z;
		FOR(i,1,n){
			cin>>pt[i].num;
			if(pt[i].num>0){
				pt[i].val=1;
				z.emplace_back(i);
			}
			else if(pt[i].num==0){
				pt[i].val=0;
			}
			else if(pt[i].num<0){
				pt[i].val=-1;
			}
		}
		presum[0]=0;
		FOR(i,1,n){
			presum[i]=presum[i-1]+pt[i].num;
		}
		FOR(i,2,z.size()){
			if(sum())
		}


	}
	return 0;
}