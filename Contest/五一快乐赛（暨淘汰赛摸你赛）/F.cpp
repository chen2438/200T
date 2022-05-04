#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define int long long
const int N=4e5+10;

struct Edge{//边的结构体 
    int to,nxt;
}e[N*2];

int adt,head[N];

void add(int u,int v){//加边建树 
    e[++adt]={v,head[u]};
    head[u]=adt;
}

int fa[N],cntp[N];

void dfs(int p1){//递归实现dfs 
    cntp[p1]=1;
    for(int i=head[p1];i!=0;i=e[i].nxt){
        int p2=e[i].to;
        if(p2==fa[p1]) continue;
        fa[p2]=p1;//点p2的父节点是点p1 
        dfs(p2);
        cntp[p1]+=cntp[e[i].to];//统计子节点个数 
        //cntp[p1]+=dfs(p2);
    }
    //return cntp[p1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<cntp[i]<<' ';
    }
    return 0;
}