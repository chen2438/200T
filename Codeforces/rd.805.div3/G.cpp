#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int N = 2e5+7, M = N * 2;
const int Layer = 32-1;

int n, m, k, p[N];
int depth[N], fa[N][Layer+1];

struct Edge{
	int to,nxt;
}e[M];

int adt,head[N];

void add(int u,int v){
	e[++adt]={v,head[u]};
	head[u]=adt;
}

void bfs(int root){
    queue<int> q;
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    q.push(root);
    while (!q.empty()){
        int t = q.front();q.pop();
        for (int i = head[t]; i; i = e[i].nxt){
            int j = e[i].to;
            if (depth[j] > depth[t] + 1){
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t;
                FOR(k,1,Layer)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    ROF(k,Layer,0)
        if (depth[fa[a][k]] >= depth[b]) a = fa[a][k];
    if (a == b) return a;
    ROF(k,Layer,0){
        if (fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int dis(int x, int y){
    return depth[x]+depth[y]-depth[lca(x, y)]*2;
}

int longest(int x){
	int max0=0,pos;
	FOR(i,1,k){
		if(max0<dis(p[x],p[i])) max0=dis(p[x],p[i]),pos=i;
	}
	return pos;
}

void solve(){
	cin>>n;
	FOR(i,1,n-1){
		int a,b; cin>>a>>b;
		add(a,b),add(b,a);
	}
	bfs(1);
	cin>>m;
	while(m--){
		cin>>k;
		FOR(i,1,k) cin>>p[i];
		int l=longest(1);
		int r=longest(l);
		int dismax=dis(p[l],p[r]);
		int ans=1;
		FOR(i,1,k){
			if(dis(p[l],p[i])+dis(p[i],p[r])!=dismax){
				ans=0;break;
			}
		}
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;//cin>>T;
    while(T--){
        solve();
    }
	return 0;
}