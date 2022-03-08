#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset(a,0,sizeof(a))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define scan(a) scanf("%d",&(a))
#define abss(x) ((x)>(0)?(x):(-1)*(x))
using namespace std;

const int maxn=1e5+7;

struct node{
    int x,y;
    bool operator< (node &T){
        return 
    }
};

set<int> s;
vector<node> v[maxn+1];

long long sum;
int n,m;

int main(){
    cin>>n>>m;
    int o;
    FOR(i,1,n){
        FOR(j,1,m){
            scanf("%d",&o);
            v[o].push_back({i,j});
            //s.insert(o);
        }
    }
    FOR(o,1,maxn){
        if(v[o].empty()) continue;
        const int _n=v[o].size();
        FOR(i,0,_n-1){
            FOR(j,i+1,_n-1){
                sum+=abss(v[o][i].x-v[o][j].x)+abss(v[o][i].y-v[o][j].y);
            }
        }
    }
    cout<<sum<<'\n';
    return 0;
}