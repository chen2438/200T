https://codeforces.com/contest/381/problem/B

### 标签

数组操作

### 题意

给定长度为 m 的数组 b. 从数组 b 中取数, 并将其排列成如下状态:

​	a[1] < a[2] < ... < a[i-1] < a[i] > a[i+1] >... > a[n-1] >a[n], n <= m.

求出能获得的最长的序列.

### 思路

发现排列是严格递增递减的, 相同的数最多出现 2 次, 最大数只能出现 1 次.

先对 b 升序排序, 以获得严格递增的序列, 去掉已获得的数.

再对 b 降序排序, 以获得严格递减的序列.

### 代码

![image-20220703204318574](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207032043605.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int N = 1e5+7;
int b[N],ans[N];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	FOR(i,1,n) cin>>b[i];
	sort(b+1,b+n+1);
	int pos=1;
	FOR(i,1,n){
		if(ans[pos-1]<b[i]){
			ans[pos]=b[i];
			b[i]=0;
			pos++;
		}
	}
	sort(b+1,b+n+1,greater<int>());
	FOR(i,1,n){
		if(b[i]==0) break;
		if(ans[pos-1]>b[i]){
			ans[pos]=b[i];
			b[i]=0;
			pos++;
		}
	}
	cout<<pos-1<<endl;
	FOR(i,1,pos-1) cout<<ans[i]<<' ';
	return 0;
}
```

