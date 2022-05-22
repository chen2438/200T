#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define LL long long
const int N = 2e6+7;
LL dat[100]={0,1};
int n,m,q;
int w[N];
struct Node
{
    int l, r;
    LL sum;
}tr[N * 4];

void pushup(Node &u, Node &l, Node &r)
{
    u.sum = l.sum | r.sum;
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, w[r]};
    else
    {
        tr[u] = {l, r};
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, LL v)
{
    if (tr[u].l == x && tr[u].r == x) tr[u].sum^=v;
    else
    {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

Node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    else
    {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (r <= mid) return query(u << 1, l, r);
        else if (l > mid) return query(u << 1 | 1, l, r);
        else
        {
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

/*int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    build(1, 1, n);

    int k, x, y;
    while (m -- )
    {
        scanf("%d%d%d", &k, &x, &y);
        if (k == 1)
        {
            if (x > y) swap(x, y);
            printf("sum=%d\n", query(1, x, y).sum);
            printf("max=%d\n", query(1, x, y).max0);
        }
        else modify(1, x, y);
    }

    return 0;
}*/
void Print(int u, int l, int r)
{
    if (l == r) printf("l=%d,r=%d,sum=%d\n",tr[u].l,tr[u].r,tr[u].sum);
    else
    {
        int mid = (l + r) >> 1;
        printf("l=%d,r=%d,sum=%d\n",tr[u].l,tr[u].r,tr[u].sum);
        Print(u << 1, l, mid), Print(u << 1 | 1, mid + 1, r);
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
        Print(1,1,n),cout<<endl;
        cin>>o>>l>>r>>x;
        if (o == 1)
        {
            FOR(i,l,r){
                modify(1, i,dat[x]);
            }
        }
        else{
            if(query(1, l, r).sum&dat[x]) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}