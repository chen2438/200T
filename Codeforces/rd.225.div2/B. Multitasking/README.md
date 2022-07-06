https://codeforces.com/contest/384/problem/B

### 标签

贪心

### 题意

给定 n 个数组, 每个数组有 m 个元素. 需要对这 n 个数组进行排序.

一次操作可以选择 2 个不同的下标 i, j , 当 a[i] > a[j] 时会交换这 2 个元素.

一次操作将会交换所有数组中满足条件 (a[i] > a[j]) 的对应下标的数.

找到一个选择 i, j 的序列{(i1, j1), (i2, j2), ... }, 最长 m(m-1)/2, 使得所有数组完成升序 (k = 0) 或降序 (k = 1) 排序.

### 思路

注意, 即使某一次操作不满足条件, 我们仍可以输出所选择的 i, j.

可以把操作序列填满, 只要按照 **选择排序** 的顺序输出所有 i, j 即可.

这样操作序列正好有 m(m-1)/2 的长度.

### 代码

![image-20220706161315703](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-06-081316.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int n,m,t;
	cin>>n>>m>>t;
	cout<<m*(m-1)/2<<endl;
	FOR(i,1,m){
		FOR(j,i+1,m){
			if(t) cout<<j<<" "<<i<<endl;
			else cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}
```

