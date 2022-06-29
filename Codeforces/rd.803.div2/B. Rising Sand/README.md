https://codeforces.com/contest/1698/problem/B

### 标签

数组操作

### 题意

给定长度为 n 的数组 a. 对于 1 < i < n, 如果 a[i] > a[i - 1] + a[i + 1], 定义 a[i] 为 **too tall**. 

给定正整数 k, 在 1 次操作中, 你可以将连续 k 个数 + 1(a[i] = a[i] + 1).

输出在任意次操作后, 数组中可以存在最多多少个 **too tall** 的数.

### 思路

如果 k=1, 简单 ~~模拟~~ 推演以下便可得到 ans = (int) (n - 1) / 2.

如果 k>1, 如果想把中间的数增大, 不可避免地会增大旁边的数. 从而导致 2 个数的差不变, 无法为形成 **too tall** 作出贡献. 因此, 所有的操作都是无效的. 只需要输出原始数组有多少个 **too tall** 即可.

### 代码

![image-20220629104958619](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206291049668.png)

![image-20220629105005918](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206291050948.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define MAXN (int)2e5+7
int a[MAXN];

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,k;cin>>n>>k;
		FOR(i,1,n) scanf("%d",&a[i]);
		if(k==1) cout<<(n-1)/2<<'\n';
		else{
			int ans=0;
			FOR(i,2,n-1) if(a[i]>a[i-1]+a[i+1]) ans++;
			cout<<ans<<'\n';
		}
	}
	return 0;
}
```

