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

const int maxn=1007;
int n,m;
struct edge{
    int next,to;
}e[maxn];
int head[maxn],tot,val[maxn],dp[maxn][maxn];

void add(int x,int y){
    e[++tot].next=head[x];
    head[x]=tot;
    e[tot].to=y;
}

void dfs(int u,int t){
    if(t<=0) return ;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        FOR(k,0,t-1)
            dp[v][k]=dp[u][k]+val[v];
        dfs(v,t-1);
        FOR(k,1,t)
            dp[u][k]=max(dp[u][k],dp[v][k-1]);
    }
}

int main(){
    cin>>n>>m;
    FOR(i,1,n){
        int a;
        cin>>a>>val[i];
        add(a,i);
    }
    dfs(0,m);
    cout<<dp[0][m];
    return 0;
}
