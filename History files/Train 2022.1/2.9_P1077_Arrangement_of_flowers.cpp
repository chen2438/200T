//#pragma GCC optimize(2)
//std::ios::sync_with_stdio(0)
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

const int maxn=107;
#define mod 1000007;
int n,m,a[maxn],mem[maxn][maxn];

int dfs(int x,int k){
    if(k>m) return 0;
    if(k==m) return 1;
    if(x==n+1) return 0;
    if(mem[x][k]) return mem[x][k];
    int ans=0;
    FOR(i,0,a[x])
        ans=(ans+dfs(x+1,k+i))%mod;
    return mem[x][k]=ans;
}

int main(){
    cin>>n>>m;
    FOR(i,1,n)
        cin>>a[i];
    cout<<dfs(1,0);
    return 0;
}