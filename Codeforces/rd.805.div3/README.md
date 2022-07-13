[Codeforces Round #805 (Div. 3)](https://codeforces.com/contest/1702)

## A. Round Down the Price

### 标签

暴力

### 题意

给定 m, 使其变成不大于 m 的最接近的 10 的幂, 输出它们的差值.

<img src="http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-13-074958.png" alt="image-20220713154958690" style="zoom:50%;" />

### 代码

![image-20220713154504998](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-13-074505.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		ROF(i,10,0){
			int dif=1;
			FOR(j,1,i) dif*=10;
			if(n-dif>=0){
				cout<<n-dif<<endl;
				break;
			}
		}
	}
	return 0;
}
```

## B. Polycarp Writes a String from Memory

### 标签

模拟

### 题意

Polycarp 每次只能记住最多 3 个不同的字母.

他想用最小的次数写一个非空小写字母字符串, 问最小次数.

![image-20220713155044785](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-13-075045.png)

### 代码

![image-20220713155209650](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-13-075210.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		string s;cin>>s;
		set<char> st;
		int ans=0;
		FOR(i,0,s.size()-1){
			if(st.count(s[i])) continue;
			if(st.size()==3) {ans++;st.clear();}
			st.insert(s[i]);
		}
		if(st.size()) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
```

## C. Train and Queries

### 标签

构造

### 题意

给定可能有重复元素的长度为 n 的数组 u 和 k 次询问.

对于每次询问, 确定元素 a 是否在元素 b 的左边.

### 思路

确定相同元素的最左边和最右边的位置, 如果 a 的最左边 < b 的最右边, 那么符合题意.

注意元素的范围较大, 可以开个 map 来存每个元素的信息

### 代码

![image-20220713160101344](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-13-080101.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

unordered_map<string,int> ml,mr;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		ml.clear();
		mr.clear();
		int n,k;cin>>n>>k;
		FOR(i,1,n){
			string s;cin>>s;
			if(ml[s]!=0) mr[s]=i;
			else ml[s]=mr[s]=i;
		}
		while(k--){
			string l,r;cin>>l>>r;
			if(ml[l]==0 or ml[r]==0) {cout<<"NO"<<endl;continue;}
			if(ml[l]<=mr[r]) {cout<<"YES"<<endl;continue;}
			else {cout<<"NO"<<endl;continue;}
		}
	}
	return 0;
}
```

## D. Not a Cheap String

### 标签

构造, 贪心

### 题意

给定字符串 w 和整数 p, 定义字符串的价值为 $\sum{w[i]-'a'+1}$, 现在要删掉最少的字符，使得删除后的字符串的价值 小于等于 p. 

输出删除后的字符串, 可能是空串.

### 思路

预处理各个字符的下标, 每次删掉最大的字符.

### 代码

![image-20220713161242697](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-13-081243.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		vector<int> gs[30];
		string s;
		int p;
		cin>>s>>p;
		int sum=0;
		FOR(i,0,s.size()-1){
			gs[s[i]-'a'+1].push_back(i);
			sum+=s[i]-'a'+1;
		}
		string ans=s;
		ROF(i,26,1){
			if(sum<=p) break;
			if(gs[i].size()){
				for(auto j:gs[i]){
					if(sum<=p) break;
					sum-=i;
					ans[j]='!';
				}
			}
		}
		FOR(i,0,ans.size()-1) if(ans[i]!='!') cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
```

## E. Split Into Two Sets

### 标签

二分图染色

### 题意

给 n (偶数) 张牌，每个牌上面有两个整数，现在要把这 n 张牌分为两个集合，问是否存在一种分法，使得每个集合内的数各不相等。

### 思路

二分图染色. 但不能用 $O(n^2)$ 建图的过程, 见代码注释.

### 代码

![image-20220713161838422](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-13-081838.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int N = 2e5+7;
const int M = 4e5+7;

vector<int> inv[N];

struct Edge{
	int to,nxt;
}e[M];

int adt,head[N],color[N];

void add(int u,int v){
	e[++adt]={v,head[u]};
	head[u]=adt;
}

bool dfs(int p1,int col){
	color[p1] = col;
	for(int i=head[p1];i!=0;i=e[i].nxt){
		int p2=e[i].to;
		if(color[p2] == col) return false;
		if(!color[p2] and !dfs(p2,3-col)) return false;
	}
	return true;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		FOR(i,1,n) inv[i].clear();
		mem(color),mem(e),mem(head);
		adt=0;
		int ans=1;
		FOR(i,1,n){
			int a,b;cin>>a>>b;
			inv[a].push_back(i);
			inv[b].push_back(i);
			//骨牌[i]={ai,bi}, 骨牌[j]={aj,bj}
			//若ai=aj,则inv[ai]=inv[aj]={i,j}
			//inv[x]表示有2张骨牌{i,j}拥有同一个数字x
			//那么i,j间需要建一条边
		}
		FOR(i,1,n) if(inv[i].size()!=2) {ans=0;break;}
		if(!ans) {puts("No");continue;}
		FOR(i,1,n){
			add(inv[i][0],inv[i][1]);
			add(inv[i][1],inv[i][0]);
		}
		FOR(i,1,n)
			if(!color[i] and !dfs(i, 1)) {ans=0; break;}
		if(ans) puts("Yes");
    	else puts("No");
	}
	return 0;
}
```

## F. Equate Multisets

### 标签

构造

### 题意

给定 2 个多重集 a, b.

对 b 有 2 个操作:

1. b[i] = b[i] * 2.
2. b[i] = b[i] / 2. (向下取整)

问能否在任意次操作后使 a = b.

### 思路

注意到仅有操作 2 能实际上改变 b 的元素的值.

让 a 和 b 不断的进行操作 2 直到全部为奇数, 此时把相等的元素删去, 再让 b 的元素不断除以 2 , 直到与 a 中剩下的元素相等.

### 代码

![image-20220713162717668](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-13-082718.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

int a[200007],b[200007];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		FOR(i,1,n) cin>>a[i];
		FOR(i,1,n) cin>>b[i];
		FOR(i,1,n){
			while(a[i]%2==0) a[i]/=2;
			while(b[i]%2==0) b[i]/=2;
		}
		multiset<int> A(a+1,a+n+1);
		multiset<int> B(b+1,b+n+1);
		for(auto i:B){
			auto it=A.find(i);
			if(it!=A.end())A.erase(it);
			else{
				while(1){
					i/=2;
					if(i==0){break;}
					auto jt=A.find(i);
					if(jt!=A.end()){A.erase(jt);break;}
				}
			}
		}
		if(A.size()==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
```

## G. Passable Paths

### 标签

最近公共祖先

### 题意

给一棵树和 q 次询问, 每次询问给 k 个点, 问这 k 个点是否在一条链上.

### 思路

使用 LCA 获得 2 个点之间的距离.

```cpp
int dis(int x, int y){
    return depth[x]+depth[y]-depth[lca(x, y)]*2;
}
```

先求这条链的两个端点 p[l],p[r], 然后对于其他 k - 2 个点判断 dis(p[l], p[r]) = dis(p[l], p[i]) + dis(p[i], p[r]) 是否成立. 如果不成立, 则不在一条链上.

### 代码

![image-20220713163653752](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-13-083654.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int N = 2e5+7, M = N * 2;
const int Layer = 32-1;

int n, m, k, p[N];
int depth[N], fa[N][Layer+1];

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

int dis(int x, int y){
    return depth[x]+depth[y]-depth[lca(x, y)]*2;
}

int longest(int x){
	int max0=0,pos;
	FOR(i,1,k){
		if(max0<dis(p[x],p[i])) max0=dis(p[x],p[i]),pos=i;
	}
	return pos;
}

void solve(){
	cin>>n;
	FOR(i,1,n-1){
		int a,b; cin>>a>>b;
		add(a,b),add(b,a);
	}
	bfs(1);
	cin>>m;
	while(m--){
		cin>>k;
		FOR(i,1,k) cin>>p[i];
		int l=longest(1);
		int r=longest(l);
		int dismax=dis(p[l],p[r]);
		int ans=1;
		FOR(i,1,k){
			if(dis(p[l],p[i])+dis(p[i],p[r])!=dismax){
				ans=0;break;
			}
		}
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;//cin>>T;
    while(T--){
        solve();
    }
	return 0;
}
```

