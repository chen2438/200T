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

int f[10007];

int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}

int main(){
    int n,m,p;
    cin>>n>>m>>p;
    FOR(i,1,n)
        f[i]=i;

    int x,y;
    FOR(i,1,m){
        cin>>x>>y;
        f[find(x)]=find(y);
    }
    FOR(i,1,p){
        cin>>x>>y;
        if(find(x)==find(y)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}