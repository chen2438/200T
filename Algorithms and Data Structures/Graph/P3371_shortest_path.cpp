#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn=1e5+7;
const int maxm=2e5+7;
const int INF=(1<<30);

int n,m,s;
int dis[maxn],vst[maxn];
int head[maxm],adt;

struct Edge{
	int to,nxt,w;
}e[maxm];

void add(int u,int v,int w){
    e[++adt]={v,head[u],w};
    head[u]=adt;
}

struct node{
    int dis,u;
    bool operator <(const node &x)const{
        return x.dis<dis;
    }
};

void dijkstra(){
	priority_queue<node> q;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vst[u]) continue;
		vst[u]=1;
		for(int i=head[u];i;i=e[i].nxt){ 
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vst[v]) q.push({dis[v],v});
			}
		}
	}
}

int main(){
	cin>>n>>m>>s;
	FOR(i,1,n)
		dis[i]=INF;
	dis[s]=0;
	FOR(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	dijkstra();
	FOR(i,1,n){
		if(dis[i]!=INF) cout<<dis[i]<<" ";
		else cout<<INT_MAX<<" ";
	}
	return 0;
}