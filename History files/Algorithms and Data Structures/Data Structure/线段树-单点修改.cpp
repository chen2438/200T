//单点修改，区间查询最大值

#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

typedef long long LL;

const int N = 200010;

int n,m;//n个数,m次操作
int w[N];//线段树模拟的数组

struct Node{
    int l, r;
    int v;  // 区间[l, r]中的最大值
}tr[N * 4];

void pushup(int u){ // 由子节点的信息，来计算父节点的信息
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r){
    if (l == r){
        tr[u] = {l, r, w[l]};
    }
    else{
        tr[u] = {l, r};
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    
}

int query(int u, int l, int r){
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;   // 树中节点，已经被完全包含在[l, r]中了

    int mid = (tr[u].l + tr[u].r) >> 1;
    int v = 0;
    if (l <= mid) v = query(u << 1, l, r);
    if (r > mid) v = max(v, query(u << 1 | 1, l, r));

    return v;
}

void modify(int u, int x, int v){
    if (tr[u].l == x && tr[u].r == x) tr[u].v = v;
    else{
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;//n个点，m次操作
    FOR(i,1,n){
        cin>>w[i];
    }
    build(1, 1, n);

    int op,l,r,k,ans;
    while (m -- ){
        cin>>op;
        if (op == 1){
            cin>>l>>r;
            ans = query(1, l, r);
            cout<<ans<<'\n';
        }
        else{
            cin>>l>>k;//修改位置l的数为k
            modify(1, l, k);
        }
    }

    return 0;
}
