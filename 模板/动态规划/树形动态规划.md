### C. Infected Tree

https://codeforces.com/contest/1689/problem/C

#### 题意

![image-20220810211948183](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208102119236.png)

#### 思路

![image-20220810212036774](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208102120840.png)

#### 代码

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 3e5+7, M=N*2;

namespace TRCD{
    struct Edge{
    	int to,nxt;
    }e[M];
    int adt,head[N];
    void add(int u,int v){
    	e[++adt]={v,head[u]};
    	head[u]=adt;
    }
    int sz[N], fa[N];
    int dp[N];
    void dfs1(int u, int father){
        fa[u] = father, sz[u] = 1;
        int left=0,right=0;
        for (int i = head[u]; i; i = e[i].nxt){
            int j = e[i].to;
            if (j == fa[u]) continue;
            dfs1(j, u);
            sz[u] += sz[j];
            if(!left) left=j;
            else if(!right) right=j;
        }
        if(!left) dp[u]=0;
        else if(!right) dp[u]=sz[left]-1;
        else dp[u]=max({0,sz[left]-1+dp[right],sz[right]-1+dp[left]});
    }
}using namespace TRCD;

void solve(){
    int n; cin>>n;
    adt=0;
    FOR(i,0,n) head[i]=dp[i]=0;
    FOR(i,1,n-1){
        int a, b; cin>>a>>b;
        add(a, b), add(b, a);
    }
    dfs1(1, -1);
    cout<<dp[1]<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

