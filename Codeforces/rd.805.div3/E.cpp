#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int N = 2e5+7;
const int M = 4e5+7;

vector<int> inv[N];

struct Edge{
	int to,nxt;
}e[M];

int adt,head[N],color[N];

void add(int u,int v){
	e[++adt]={v,head[u]};
	head[u]=adt;
}

bool dfs(int p1,int col){
	color[p1] = col;
	for(int i=head[p1];i!=0;i=e[i].nxt){
		int p2=e[i].to;
		if(color[p2] == col) return false;
		if(!color[p2] and !dfs(p2,3-col)) return false;
	}
	return true;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		FOR(i,1,n) inv[i].clear();
		mem(color),mem(e),mem(head);
		adt=0;
		int ans=1;
		FOR(i,1,n){
			int a,b;cin>>a>>b;
			inv[a].push_back(i);
			inv[b].push_back(i);
			//骨牌[i]={ai,bi}, 骨牌[j]={aj,bj}
			//若ai=aj,则inv[ai]=inv[aj]={i,j}
			//inv[x]表示有2张骨牌{i,j}拥有同一个数字x
			//那么i,j间需要建一条边
		}
		FOR(i,1,n) if(inv[i].size()!=2) {ans=0;break;}
		if(!ans) {puts("No");continue;}
		FOR(i,1,n){
			add(inv[i][0],inv[i][1]);
			add(inv[i][1],inv[i][0]);
		}
		FOR(i,1,n)
			if(!color[i] and !dfs(i, 1)) {ans=0; break;}
		if(ans) puts("Yes");
    	else puts("No");
	}
	return 0;
}