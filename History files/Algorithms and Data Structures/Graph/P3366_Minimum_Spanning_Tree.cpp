#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

struct Edge{
    int u,v,w;
}edge[200005];

int fa[5005],n,m;

bool cmp(Edge a,Edge b){
    return a.w<b.w;
}

int find(int x){
    while(x!=fa[x])
        x=fa[x]=fa[fa[x]];
    return x;
}

int kruskal(){
    int eu,ev,cnt=0,ans=0;
    sort(edge,edge+m,cmp);
    FOR(i,0,m-1){
        eu=find(edge[i].u),ev=find(edge[i].v);
        if(eu==ev) continue;
        ans+=edge[i].w;
        fa[ev]=eu;
        if(++cnt==n-1) break;
    }
    return ans;
}

bool is_connected(){
    int cnt=0;
    FOR(i,1,n){
        if(fa[i]==i) cnt++;
    }
    if(cnt==1) return true;
    else return false;
}

int main(){
    cin>>n>>m;
    FOR(i,1,n)
        fa[i]=i;
    FOR(i,0,m-1){
        int u,v,w;
        cin>>u>>v>>w;
        edge[i]={u,v,w};
    }
    int res=kruskal();
    if(is_connected()) cout<<res;
    else cout<<"orz";
    return 0;
}