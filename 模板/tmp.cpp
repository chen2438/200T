#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
<<<<<<< Updated upstream
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
=======
using namespace std;

const int N = 2e5+7, M = N * 2;

int n, m, k;
int depth[N], fa[N][32];
int v[N],key[N],stkey[N];
int resa[N], resb[N];

vector<int> numkey[N];
const int Layer = 31;

struct Edge{
    int to,nxt;
}e[M];

int adt,head[N];

void add(int u,int v){
    e[++adt]={v,head[u]};
    head[u]=adt;
}

void bfs(int root){
    queue<int> q;
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    q.push(root);
    while (!q.empty()){
        int t = q.front();q.pop();
        for (int i = head[t]; i; i = e[i].nxt){
            int j = e[i].to;
            if (depth[j] > depth[t] + 1){
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t;
                FOR(k,1,Layer)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

void dfs_lca_sub(int root, int p1){
    for(int i=head[p1];i;i=e[i].nxt){
        int p2=e[i].to;
        // printf("sub_p2=%d\n",p2);
        if(stkey[p2]) numkey[root].push_back(p2);
        dfs_lca_sub(root,p2);
    }
}

void dfs_lca_root(int root){
    for(int i=head[root];i;i=e[i].nxt){
        int p2=e[i].to;
        // printf("root_p2=%d\n",p2);
        if(stkey[p2]) numkey[p2].push_back(p2);
        dfs_lca_sub(p2,p2);
        if(numkey[p2].size()==1)
            numkey[root].push_back(numkey[p2][0]);
        if(numkey[p2].size()>1)
            numkey[root].push_back(-1);

    }
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    ROF(k,Layer,0)
        if (depth[fa[a][k]] >= depth[b]) a = fa[a][k];
    if (a == b) return a;
    ROF(k,Layer,0){
        if (fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<int> dela,delb;
    cin>>n>>k;
    FOR(i,1,k) {cin>>key[i];stkey[key[i]]=1;}
    FOR(i,1,n) cin>>v[i];
    FOR(i,1,n-1){
        int a; cin>>a;
        add(a, i+1);// add(i+1, a);
    }
    bfs(1);
    int lca_root = key[1];
    FOR(i,2,k) lca_root=lca(lca_root,key[i]);
    // cout<<"lca_root="<<lca_root<<endl;
    dfs_lca_root(lca_root);
    // cout<<"numkey[lca_root].size()="<<numkey[lca_root].size()<<endl;
    // for(auto i:numkey[lca_root])
    //     cout<<i<<" ";puts("");
    if(numkey[lca_root].size()==1)
        dela.push_back(lca_root);
    if(numkey[lca_root].size()==2){
        for(auto i:numkey[lca_root])
            if(i!=-1) dela.push_back(i);
    }
    FOR(i,1,k) resa[key[i]]=v[lca_root];
    for(auto i:dela){
        int lca_root;
        if(i==key[1]) lca_root=key[2];
        else lca_root=key[1];
        FOR(j,2,k){
            if(i==key[j]) continue;
            lca_root = lca(lca_root,key[j]);
        }
        resa[i]=v[lca_root];
    }
    
    /*----------------------------------------*/
    mem(depth),mem(fa),mem(v),mem(e),mem(head);
    adt=0;
    FOR(i,1,n) numkey[i].clear();
    /*----------------------------------------*/
    
    FOR(i,1,n) cin>>v[i];
    FOR(i,1,n-1){
        int a; cin>>a;
        add(a, i+1);// add(i+1, a);
    }
    bfs(1);
    lca_root = key[1];
    FOR(i,2,k) lca_root = lca(lca_root,key[i]);
    dfs_lca_root(lca_root);
    if(numkey[lca_root].size()==1)
        delb.push_back(lca_root);
    if(numkey[lca_root].size()==2){
        for(auto i:numkey[lca_root])
            if(i!=-1) delb.push_back(i);
    }
    FOR(i,1,k) resb[key[i]]=v[lca_root];
    for(auto i:delb){
        int lca_root;
        if(i==key[1]) lca_root=key[2];
        else lca_root=key[1];
        FOR(j,2,k){
            if(i==key[j]) continue;
            lca_root = lca(lca_root,key[j]);
        }
        resb[i]=v[lca_root];
    }
    int ans=0;
    FOR(i,1,k){
        if(resa[key[i]]>resb[key[i]]) ans++;
    }
    // FOR(i,1,k) cout<<resa[key[i]]<<" ";
    // cout<<endl;
    // FOR(i,1,k) cout<<resb[key[i]]<<" ";
    // cout<<endl;
    cout<<ans<<endl;
>>>>>>> Stashed changes
    return 0;
}
