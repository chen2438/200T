## B. Permutation

https://codeforces.com/contest/1701/problem/B

### 标签

贪心, 排列

### 题意

对于一个正整数 d, 定义长度为 n 的排列 p 的花费是使得 p[i] * d = p[i + 1] 成立的下标 i 的数量.

给定 n, 对于长度为 n 的排列 p, 找到有最大花费的 d 和这个排列.

如果有多个答案, 输出任意一个.

### 思路

贪心.

在排列中, 使得后一项是前一项的 2 倍, 即 d = 2, 可以获得最大花费.

例如 n = 6, p={1, 2, 4, 3, 6, 5};

### 代码

![image-20220709132552709](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-09-052552.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

vector<int> a;
array<int,200007> vst;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		a.clear();
		vst.fill(0);
		int n;cin>>n;
		FOR(i,1,n){
			if(vst[i]) continue;
			for(int j=i;j<=n and !vst[j];j*=2){
				vst[j]=1;
				a.push_back(j);
			}
		}
		cout<<2<<endl;
		for(auto i:a) cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
```

