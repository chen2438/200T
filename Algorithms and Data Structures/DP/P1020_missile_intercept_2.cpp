//#pragma GCC optimize(2)
//clock_t st=clock();
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

const int maxn=1e5+7;
int n,a[maxn];
int mem1[maxn],mem2[maxn];

int dfs1(int p){
	if(mem1[p]!=0) return mem1[p];
	int res=1;
	FOR(i,p+1,n)
		if(a[p]>=a[i]) res=max(res,dfs1(i)+1);
	return mem1[p]=res;
}

int dfs2(int p){
	if(mem2[p]!=0) return mem2[p];
	int res=1;
	FOR(i,p+1,n)
		if(a[p]<a[i]) res=max(res,dfs2(i)+1);
	return mem2[p]=res;
}

int main(){
	n=1;
	while(cin>>a[n]) ++n;
	n--;

	ROF(i,n,1){
		dfs1(i);
		dfs2(i);
	}
	int ans1=0,ans2=0;
	FOR(i,1,n){
		ans1=max(ans1,mem1[i]);
		ans2=max(ans2,mem2[i]);
	}
	cout<<ans1<<"\n"<<ans2;;
}