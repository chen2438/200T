#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define inf (1<<30)
#define maxn 5005
#define maxm 200005
struct edge{
	int v,w,next;
}e[maxm<<1];//无向图开两倍数组
int n,m;
int dis[maxn],now=1,ans;
//dis[]=已经加入最小生成树的的点到没加入点的最短距离
//比如说1和2号节点已经加入了最小生成树，那么dis[3]就等于min(1->3,2->3)
bool vis[maxn];

int head[maxn],cnt;
void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

int prim(){
	FOR(i,2,n)
		dis[i]=inf;
	for(int i=head[1];i;i=e[i].next)
		dis[e[i].v]=min(dis[e[i].v],e[i].w);
    FOR(j,1,n-1){
        int minn=inf;
        vis[now]=1;
        FOR(i,1,n){
            if(!vis[i] and minn>dis[i]){
                minn=dis[i];
				now=i;
            }
        }
        if(minn==inf) return 0;
        ans+=minn;
        for(int i=head[now];i;i=e[i].next){
        	int v=e[i].v;
        	if(!vis[v] and dis[v]>e[i].w) dis[v]=e[i].w;
		}
    }
    return ans;
}

int main(){
    cin>>n>>m;
    FOR(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w),add(v,u,w);
    }
    int res=prim();
    if(res) cout<<res;
    else cout<<"orz";
    return 0;
}