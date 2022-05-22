#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 2e6+7;
ULL dat[100]={0,1};
int n,m,q;
int w[N];
struct Node
{
    int l, r;
    ULL sum,add;
    ULL sam;
}tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum | tr[u << 1 | 1].sum;
    tr[u].sam = ~(tr[u << 1].sum ^ tr[u << 1 | 1].sum);
    //cout<<"pushup:~sam="<<(tr[u << 1].sum ^ tr[u << 1 | 1].sum)<<endl;
}

void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add)
    {
        left.add ^= root.add;
        //left.sum |= root.add;
        left.sum = tr[(u<<1)<<1].add ^ left.add | tr[(u<<1)<<1|1].add ^ left.add;
        //left.sum ^= (left.sam & root.add);


        right.add ^= root.add;
        //right.sum |= root.add;
        right.sum = tr[(u<<1)<<1].add ^ right.add | tr[(u<<1)<<1|1].add ^ right.add;
        //right.sum ^= (right.sam & root.add);

        root.add = 0;
    }
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, 0, 0,(~(ULL)0)};
    else
    {
        tr[u] = {l, r,0,0};
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void Print(int u, int l, int r)
{
    if (l == r){ printf("l=%d,r=%d,sum=%d,add=%d",tr[u].l,tr[u].r,tr[u].sum,tr[u].add);cout<<",sam="<<tr[u].sam<<endl;}
    else
    {
        int mid = (l + r) >> 1;
         printf("l=%d,r=%d,sum=%d,add=%d",tr[u].l,tr[u].r,tr[u].sum,tr[u].add);cout<<",sam="<<tr[u].sam<<endl;
        Print(u << 1, l, mid), Print(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u, int l, int r, ULL d)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].add ^= d;
        //tr[u].sum ^= (tr[u].sam & d);
        tr[u].sum = tr[u<<1].sum ^ tr[u].add | tr[u<<1|1].sum ^ tr[u].add;
    }
    else
    {
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

ULL query(int u, int l, int r)
{
    //pushup(u);
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    LL sum = 0;
    if (l <= mid) sum = query(u << 1, l, r);
    if (r > mid) sum |= query(u << 1 | 1, l, r);
    return sum;
}


int main()
{
    //cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>q;
    FOR(i,2,62){
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
            modify(1, l, r, dat[x]);
        }
        else{
            //cout<<query(1, l, r);
            if(query(1, l, r)&dat[x]) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
/*
4 10 10
1 1 2 2
1 3 4 1
1 3 3 2
1 1 4 2
2 1 4 2
*/