/*
#pragma GCC optimize(2)
std::ios::sync_with_stdio(0)
clock_t st=clock();
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#define PI acos(-1.0)
*/
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

struct Node{
    int x,y;
}fa[207][207],a,b;

Node Find(Node t){
    if(fa[t.x][t.y].x==t.x and fa[t.x][t.y].y==t.y) return t;
    else return fa[t.x][t.y]=Find(fa[t.x][t.y]);
}

int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,1,n) FOR(j,1,n)
        fa[i][j].x=i,fa[i][j].y=j;
 
    FOR(i,1,m){
        int x,y;
        char ch[10];
        cin>>x>>y>>ch;
        if(ch[0]=='D') a=Find(fa[x][y]),b=Find(fa[x+1][y]);
        if(ch[0]=='R') a=Find(fa[x][y]),b=Find(fa[x][y+1]);
        if(a.x==b.x&&a.y==b.y){
            cout<<i<<endl;
            exit(0);
        }
        else fa[b.x][b.y]=a;
    }
    cout<<"draw\n";
    return 0;
}