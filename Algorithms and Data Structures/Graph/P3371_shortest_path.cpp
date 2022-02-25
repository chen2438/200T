#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn=1e4+7;
const int maxm=5e5+7;
const int INF=(1<<30);

struct Edge{
    int u,v,w;
};

Edge edge[maxm];
int dist[maxn];//结点到源点最小距离
int n,m,s;//结点数,边数,源点

// 初始化图
void init(){
    FOR(i,1,n)
        dist[i]=INF;
    FOR(i,1,m){
    	int u,v,w;
    	cin>>u>>v>>w;
        edge[i]={u,v,w};
        if(u==s) dist[v]=w;
    }
    dist[s]=0;
}

void relax(int u,int v,int w){
    if(dist[v]>dist[u]+w) dist[v]=dist[u]+w;
}

bool Bellman_Ford(){
    FOR(i,1,n-1)
        FOR(j,1,m)
            relax(edge[j].u,edge[j].v,edge[j].w);
    bool flag=true;
    FOR(i,1,m)//判断是否有负环路
        if(dist[edge[i].v]>dist[edge[i].u]+edge[i].w){
            flag=false;
            break;
        }
    return flag;
}
int main(){
	cin>>n>>m>>s;
    init();
    if(Bellman_Ford()){
        FOR(i,1,n){
            if(dist[i]!=INF) cout<<dist[i]<<" ";
            else cout<<INT_MAX<<" ";
        }
    }
    return 0;
}