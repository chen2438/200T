## C. Helping the Nature

https://codeforces.com/contest/1700/problem/C

### 标签

差分, 贪心

### 题意

给定数组 a, 有 3 种操作.

1. 选择 i, 使 a[1 -> i] -= 1.
2. 选择 i, 使 a[i -> n] -= 1.

3. 使所有数 += 1

求使所有数变为 0 的最小操作数.

### 思路

令 b 为 a 的差分数组.

操作等价于:

1. b[1] -= 1, b[i + 1] += 1.
2. b[i] -= 1.
3. b[1] += 1.

让 a[] 相同, 等价于 b[1] = a[1], b[2 -> n] = 0.

让 a[] 全为 0, 等价于 b[1 -> n] = 0.

发现, 能对 b[2, n] 操作的只有操作 1 和操作 2, 分别对应负数变 0 和正数变 0.

这样, 我们先利用操作 1、2 把 b[2, n] 全部处理为 0, 再单独处理 b[1] 即可.

### 代码

![image-20220706133407749](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-06-053407.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int N = 2e5+7;
int a[N],b[N];

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		FOR(i,1,n) cin>>a[i];
		FOR(i,1,n) b[i]=a[i]-a[i-1];
		int ans=0;
		FOR(i,2,n){
			if(b[i]>0){ans+=b[i];}
			if(b[i]<0){ans+=-b[i];b[1]-=-b[i];}
		}
		ans+=abs(b[1]);
		cout<<ans<<endl;
	}
	return 0;
}
```

