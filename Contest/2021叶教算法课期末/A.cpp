#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn=1e4+7;
const int maxm=5e5+7;
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

void dijkstra(){
	int u=s;
	while(!vst[u]){
		int min0=INF;
		vst[u]=1;
		for(int i=head[u];i;i=e[i].nxt){ 
			int v=e[i].to,w=e[i].w;
			if(!vst[v]) dis[v]=min(dis[v],dis[u]+w);
		}
		FOR(i,1,n)
			if(!vst[i] and dis[i]<min0) min0=dis[i],u=i;
	}
}

int main(){
	int st,ed;
	cin>>n>>st>>ed;
	FOR(i,1,n)
		dis[i]=INF;
	dis[st]=0;
	FOR(i,1,n){
		FOR(j,1,n){
			int w;cin>>w;
			if(w)add(i,j,1);
		}
	}
	/*FOR(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}*/
	dijkstra();
	cout<<dis[ed]-1<<" ";
	/*FOR(i,1,n){
		if(dis[i]!=INF) cout<<dis[i]<<" ";
		else cout<<INT_MAX<<" ";
	}*/
	return 0;
}