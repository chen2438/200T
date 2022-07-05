https://codeforces.com/contest/1699/problem/C

### 标签

数组操作

### 题意

给定 0 到 n-1 的排列 a.

定义 MEX( a[l -> r] ) 为不在 a[l -> r] 中出现的最小非负整数.

若对任意 1 <= l <= r <=n, MEX( a[l -> r] ) = MEX( b[l -> r] ) 恒成立, 则称 a 与 b 相似.

求出有多少个不同的排列 b 与 a 相似. 答案对 1e9 + 7 取模.

### 思路

[参考](https://zhuanlan.zhihu.com/p/537606910)

> 首先0所在的位置是不能变的，因为这个位置的mex为1。接着考虑1的位置，处于1中间的那些数有一定的自由，而1是固定不变的。

> 我们从小到达枚举维护一个区间[l,r]，如果某个数不在区间中，则说明这个数的位置不能变，我们将区间扩展到这个数的位置为边界。如果某个数在区间中，说明它可以任意放在区间中那些自由的位置。我们记录一下区间中有多少个自由位置，每次遇到这样一个数将答案乘以自由位置的数目。

### 代码

![image-20220705143107021](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-05-063107.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long

const int N = 1e5+7;
const ll p = 1e9+7;

int f[N],g[N];//g 是 f 的反函数

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		FOR(i,0,n-1) {cin>>f[i];g[f[i]]=i;}
		ll l,r,ans=1;
		l=r=g[0];
		FOR(i,0,n-1){
			if(g[i]<l) l=g[i];
			if(r<g[i]) r=g[i];
			if(l<g[i] and g[i]<r) ans=ans*(r-l+1-i)%p;
			cout<<l<<" "<<r<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
```

