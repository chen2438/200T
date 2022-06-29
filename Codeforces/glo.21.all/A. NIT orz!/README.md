https://codeforces.com/contest/1696/problem/A

### 标签

位运算

### 题意

给定长度为 n 的数组 a, 进行以下 0 到任意次操作:

选择任意 ai, 使 ai = ai | z，z = ai & z.

输出任意次操作后数组 a 的最大值.

### 思路

ai = ai | z, ai 不严格递增

同理, z 不严格递减

如果找到一个 a[x1], 使 a[ans] = a[x1] | z 最大, 那么当 z &= a[x1] (z 变小) 时, 不可能找到其他的 a[x2] 使 a[x2] |= z 大于 a[ans].

如果找到一个 a[x3], z[x3] != a[x1], 那么 a[x3] |= z 小于 a[ans], 此时 z &= a[x3] (z 变小) , 不可能找到其他的 a[x4] 使 a[x4] |= z 大于 a[ans].

综上, 操作只能进行至多 1 次, 即找到最佳的 a[i], 使 a[ans] = a[x1] | z 最大.

### 代码

![image-20220626103313140](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206261033209.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,z;cin>>n>>z;
		int ai,ans=0;
		FOR(i,1,n){
			cin>>ai;
			ans=max(ans,ai|z);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
```

