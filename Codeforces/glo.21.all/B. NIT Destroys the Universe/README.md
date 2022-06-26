

https://codeforces.com/contest/1696/problem/B

st=10:39, ed=11:16

### 标签

数组操作

### 题意

定义 mex(S) 为不在S中出现的最小非负整数.

给定长度为 n 的数组 a, 一次操作如下:

选择任意 [l,r], 使 w = mex(a[l -> r]), 然后使 a[l -> r] = w.

输出最小操作数, 使数组 a 全部为零.

### 思路

如果 a[l->r] 中没有 0, 那么可以使它变为 0.

~~最终目标是使所有 a[i] 变为 0, 所以只有使 w = 0 是有效操作.~~

~~以 0 为间隔点, 可以依次将区间变为 0 , 统计这些没有 0 的区间的个数即可.~~

如果 a[l->r] 中有 0, 那么可以使它变为非 0, 然后再进行 1 次操作变为 0.

所以至多需要进行 2 次操作.

将删除线部分所统计的区间个数与 2 比较, 输出最小值即可.

### 代码

![image-20220626111451424](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206261114468.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,pre=0,x,ans=0;
		cin>>n;
		FOR(i,1,n){
			cin>>x;
			if(pre==0 and x!=0) ans++;
			pre=x;
		}
		cout<<min(ans,2)<<'\n';
	}
	return 0;
}
```

