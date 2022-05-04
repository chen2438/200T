#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

typedef long long LL;

const int N = 5e5+7;

int n, m;
int w[N];
struct Node
{
    int l, r;
    LL add;
    LL max0;
}tr[N * 4];

/*void pushup(int u)
{
    //tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].max0 = max(tr[u << 1].max0, tr[u << 1 | 1].max0);
}*/
void pushup(Node &u, Node &l, Node &r)
{
    //u.sum = l.sum + r.sum;
    u.max0 = max(l.max0, r.max0);
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
        left.add += root.add;
        left.max0 += (LL)root.add;
        right.add += root.add;
        right.max0 += (LL)root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, 0, w[r]};
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
        //tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d;
        tr[u].max0 += (LL)d;
        tr[u].add += d;
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
        //Node res={0,0,0,0};
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
    cin>>n>>m;

    FOR(i,1,n) cin>>w[i];

    build(1, 1, n);

    int op;
    int l, r, d;

    while (m -- )
    {
        cin>>l>>r;
        /*if (op == 1)
        {
            cin>>d;
            modify(1, l, r, d);//w[l->r]+=d;
        }*/
        {
            //printf("sum=%lld\n", query(1, l, r).sum);
            printf("%lld\n", query(1, l, r).max0);
        }
    }

    return 0;
}
/*
10 10
1 6 3 8 5 9 6 4 7 3
*/