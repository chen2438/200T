#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 1e5+7;
const int M = 1e4+7;

struct node{
    int v,idx;
    vector<int> g;
    bool operator<(const node &y)const{
        return v<y.v;
    }
}a[N];
int odd[N];
vector<int> fd[M];

int n,m;

void solve(){
    // 邀请尽可能多的成员，减小不高兴值
    // 如果邀请的成员包含对子，蛋糕+1
    // 要求蛋糕数为偶数
    // 先全选，然后删除
    // 1 10
    // 1 11
    // 2 12
    // 2 13
    // 3 14
    
    mem(odd);
    FOR(i,0,M-1) fd[i].clear();
    cin>>n>>m;
    FOR(i,1,n) {
        cin>>a[i].v;
        a[i].idx=i;
        a[i].g.clear();
        fd[a[i].v].push_back(i);
    }
    FOR(i,1,m){
        int x,y; cin>>x>>y;
        a[x].g.push_back(y);
        a[y].g.push_back(x);
    }
    //sort(a+1,a+n+1);
    // FOR(i,1,n){
    //     if(a[i].g.size()%2) odd[i]=1;
    //     else odd[i]=0;
    // }
    FOR(i,0,M-1){
        if(fd[i].empty()) continue;
        FOR(j,0,fd[i].size()-1){
            if(a[fd[i][j]].g.size()%2==0){
                FOR(k,0,i){
                    if()
                }
            }
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
