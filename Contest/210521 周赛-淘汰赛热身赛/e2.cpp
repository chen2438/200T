#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

typedef long long LL;

const int N = 2e6+7;
LL dat[100]={0,1};
int n, m,q;
int w[N];
struct Node
{
    int l, r;
    LL sum,add;
}tr[N * 4];

void pushup(Node &u, Node &l, Node &r)
{
    u.sum = l.sum | r.sum;
    //u.max0 = max(l.max0, r.max0);
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add)
    {
        left.add ^= root.add;
        left.sum ^= root.add;
        //left.max0 += (LL)root.add;

        right.add ^= root.add;
        right.sum ^= root.add;
        //right.max0 += (LL)root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, w[r], 0};
    else
    {
        tr[u] = {l, r};
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int d)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum ^= dat[d];
        //tr[u].max0 += (LL)d;
        tr[u].add ^= dat[d];
    }
    else    // 一定要分裂
    {
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

Node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    else{
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (r <= mid) return query(u << 1, l, r);
        else if (l > mid) return query(u << 1 | 1, l, r);
        else{
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>q;
    FOR(i,2,61){
        dat[i]=dat[i-1]*2;
    }

    //for (int i = 1; i <= n; i ++ ) cin>>w[i];

    build(1, 1, n);

    int o,l, r, x;

    while (q -- )
    {
        cin>>o>>l>>r>>x;
        if (o == 1)
        {
            modify(1, l, r, x);
        }
        else{
            if(query(1, l, r).sum&dat[x]) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}