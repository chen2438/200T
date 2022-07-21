# [Codeforces Round #245 (Div. 2)](https://codeforces.com/contest/430)

## C. Xor-tree

### 标签

贪心， 树的遍历

### 题意

 给出一棵树，有n个节点，根为1，每个节点的值不是0就是1，每次可以翻转一个节点，翻转后，当前节点值翻转，儿子节点值不变，儿子的儿子翻转，依次类推，求最少翻转次数，使得每个节点的值与目标结果相同。

### 思路

 由于翻转一个节点，其子节点有的会改变，因此贪心的从根开始搜索，如果当前节点与目标不同，那么一定要翻转，因为只影响子节点，因此其父节点已经到达目标结果将不受影响。

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int N=1e5+10, M=2e5+10;

struct Edge{
	int to,nxt;
}e[M];

int adt,head[N];

void add(int u,int v){
	e[++adt]={v,head[u]};
	head[u]=adt;
}

int fa[N],now[N],ed[N];
vector<int> ans;

void dfs(int p1,int layer,int odd,int even){
    if(layer%2) now[p1]^=odd;
    else now[p1]^=even;
	
	for(int i=head[p1];i!=0;i=e[i].nxt){
		int p2=e[i].to;
		if(p2==fa[p1]) continue;
		fa[p2]=p1;
		
		if((layer+1)%2) now[p2]^=odd;
        else now[p2]^=even;
        
		if(now[p2]!=ed[p2]){
		    ans.push_back(p2);
		    if((layer+1)%2) dfs(p2,layer+1,odd^1,even);
		    else dfs(p2,layer+1,odd,even^1);
		}
		else dfs(p2,layer+1,odd,even);
	}
}

void solve(){
    int n; cin>>n;
    ans.clear();
    FOR(i,1,n-1){
        int u,v; cin>>u>>v;
        add(u,v),add(v,u);
    }
    FOR(i,1,n) cin>>now[i];
    FOR(i,1,n) cin>>ed[i];
    if(now[1]!=ed[1]){
        ans.push_back(1);
        dfs(1,1,1,0);
    }
    else dfs(1,1,0,0);
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}
```

