# [Codeforces Round #806 (Div. 4)](https://codeforces.com/contest/1703)

## 提交情况

![image-20220714100333337](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-14-020333.png)

## A. YES or YES?

### 标签

暴力

### 题意

给定长度为 3 的字符串，判断该串是不是 YES (不区分大小写).

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		string s;cin>>s;
		if(s=="YES" or s=="YEs" or s=="Yes" or s=="yes" or s=="yES" or s=="yeS" or s=="YeS" or s=="yEs") cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
```

## B. ICPC Balloons

### 标签

模拟

### 题意

给定一个大写字母字符串, 每个字母第 1 次出现获得 2 个气球, 之后每出现 1 次获得 1 个气球, 求总共获得多少气球.

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		string s;cin>>s;
		int a[30]={0};
		for(auto i:s) a[i-'A'+1]++;
		int ans=0;
		FOR(i,1,26) if(a[i]>0) ans+=a[i]+1;
		cout<<ans<<endl;
	}
	return 0;
}
```

## C. Cypher

### 标签

模拟

### 题意

给定有 n 个齿轮的密码锁, 已知最后的密码锁状态和转齿轮的操作, 求密码锁初始状态.

<img src="http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-14-020735.png" alt="img" style="zoom: 50%;" />

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int ed[1000]={0};
		FOR(i,1,n) cin>>ed[i];
		string op[1000];
		FOR(i,1,n){
			int len;cin>>len;
			cin>>op[i];
			for(auto j:op[i]){
				if(j=='U') ed[i]--;
				if(j=='D') ed[i]++;
				if(ed[i]>9) ed[i]-=10;
				if(ed[i]<0) ed[i]+=10;
			}
		}
		FOR(i,1,n) cout<<ed[i]<<" ";
		cout<<endl;
	}
	return 0;
}
```

## D. Double Strings

### 标签

STL, 暴力

### 题意

给定 n 个字符串 $s[i],  i \in [1,n],$ 判断 s[i] = s[j] + s[k] 是否成立, j 与 k 可能相同.

每个字符串长度不超过 8.

### 思路

遍历 s[i], 把每个 s[i] 拆分成左右两段, 用 hash 表判断这两段是否存在, 如果存在, s[i] = s[j] + s[k] 成立.

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

vector<string> v;
unordered_map<string,int> mp;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		v.clear();
		mp.clear();
		FOR(i,0,n-1){
			string s;cin>>s;
			v.push_back(s);
			mp[s]=1;
		}
		string ans;
		for(string i:v){
			int has=0;
			FOR(j,0,i.size()-1){
				string l,r;
				l=i.substr(0,j+1);
				r=i.substr(j+1);
				if(mp[l] and mp[r]) {has=1;break;}
			}
			if(has) ans+='1';
			else ans+='0';
		}
		cout<<ans<<endl;
	}
	return 0;
}
```

## E. Mirror Grid

### 标签

构造

### 题意

给定 n * n 的 01 矩阵, 每次可以翻转 1 个格子(0→1 or 1→0)，求使矩阵旋转 90 度, 180 度, 270 度后与原矩阵相同所需的最少操作次数.

### 思路

发现 (i, j) 旋转后的 3 个点是 (j, n-i+1), (n-j+1, i), (n-i+1, n-j+1).

只要统计这 4 个点, 0 少就把 0 变 1, 1 少就把 1 变 0.

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

int matx[107][107];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		mem(matx);
		FOR(i,1,n){
			FOR(j,1,n){
				char c;cin>>c;
				if(c=='1') matx[i][j]=1;
			}
		}
		int ans=0;
		FOR(i,1,n){
			FOR(j,1,n){
				int sum=matx[i][j]+matx[j][n-i+1]+matx[n-j+1][i]+matx[n-i+1][n-j+1];
				ans+=min(4-sum,sum);
				if(sum>=2){
					matx[i][j]=matx[j][n-i+1]=matx[n-j+1][i]=matx[n-i+1][n-j+1]=1;
				}
				else{
					matx[i][j]=matx[j][n-i+1]=matx[n-j+1][i]=matx[n-i+1][n-j+1]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
```



## F. Yet Another Problem About Pairs Satisfying an Inequality

### 标签

构造

### 题意

给定长度为 n 的数组 A, 统计有多少对 $(i, j), 1 \leq i,j \leq n$ 满足 $A_i \lt i \lt A_j \lt j$.

### 思路

用数组 a 存给定的 A, 如果 A[i] 不满足 A[i] < i 则不存入数组.

a 复制 1 份给数组 b, a 按照数值大小排序, b 按照 A 存入时的数组下标排序.

遍历数组 a, 查找最接近 a[i].数值 的 b[j].下标 使得 下标 < 数值成立. 这样, 所有在 b[j] 前面的元素都满足题目条件, 累加答案即可.

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

#define int long long
const int N=2e5+7;

struct node{
	int v,idx;
};

vector<node> a,b;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		a.clear();
		int n;cin>>n;
		FOR(i,1,n){
			int v; cin>>v;
			if(v>=i) continue;
			a.push_back({v,i});
		}
		b=a;
		sort(a.begin(),a.end(),[](node &x, node &y){return x.v<y.v;});
		sort(b.begin(),b.end(),[](node &x, node &y){return x.idx<y.idx;});
		int ans=0;
		for(auto i:a){
			int l=0,r=b.size()-1;
			while(l<r){
		        int mid=(l+r)/2;
		        if(b[mid].idx<i.v) l=mid+1;
		        else r=mid;
		    }
		    ans+=r;
		}
		cout<<ans<<endl;
	}
	return 0;
}
```



## G. Good Key, Bad Key

### 标签

贪心, 动态规划

### 题意

给定 n 个箱子, 每个箱子里有 a[i] 个硬币, 开箱子的顺序必须是 1 -> n.

有好钥匙和坏钥匙, 每个好钥匙需要花费 k 个硬币购买, 允许无限负债.

使用坏钥匙后, 接下来的所有箱子(包括正在开的箱子)内的硬币减半(向下取整).

一开始没有任何钥匙, 求能获得的最大硬币数.

### 思路

优先使用好钥匙, 然后只使用坏钥匙总是最佳的.

按照这个思路模拟即可, 注意 $ \log_2 1e9 = 29.9$, 验证坏钥匙时只需要验证至多 30 个即可.

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int N = 1e5+7;
int a[N],pre[N];

void solve(){
	int n,k;
	cin>>n>>k;
	FOR(i,1,n){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	int ans=-1e9,sum=0;
	FOR(i,0,n){
		sum = -i*k;
		sum += pre[i];
		FOR(j,i+1,n){
			if(j-i-1>32)break;
			sum += a[j]>>(j-i);
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
    while(T--){
        solve();
    }
	return 0;
}
```

