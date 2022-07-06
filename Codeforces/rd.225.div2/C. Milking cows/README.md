https://codeforces.com/contest/384/problem/C

### 标签

贪心

### 题意

有 n 头奶牛站在一排, 每头牛朝左或朝右.

当对一头牛挤奶时, 所有能看到它的牛的产奶量 -1.

如果一头牛已经被挤奶, 那么它的产奶量不变.

求最小的产奶量减少量.

### 思路

从右边第 1 个朝左的牛挤奶. 依次把所有朝左的牛挤奶. 剩下的牛都是朝右, 可以设法不减少总产奶量. 

产奶量减少量即 从右往左依次把所有朝左的牛挤奶 所产生的产奶量减少量.

做一个前缀和即可.

从左边处理朝右的牛也可以.

**贪心的正确性我不会证明**

### 代码

![image-20220706165537579](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-06-085537.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define int long long
const int N=2e5+7;
int a[N],pre[N];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;

	FOR(i,1,n){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	int sum=0;
	ROF(i,n,1) if(a[i]==0) sum+=pre[i-1];
	cout<<sum<<endl;
	return 0;
}

//从右边第 1 个向左的牛处理, 不会被同类看到

//> < > < >
//0 1 0 1 0
```

