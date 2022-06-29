https://codeforces.com/contest/1698/problem/C

### 标签

数组操作

### 题意

给定长度为 n 的数组 a. 如果对任意 1 <= i < j < k <= n, 存在 1 <= l <= n, 使 a[i] + a[j] + a[k] = a[l] 成立, 则称数组 a 是 **3SUM-closed** 的.

判断数组是否是 **3SUM-closed** 的.

### 思路

(参考官方题解)

如果数组有至少 3 个正数, 选择最大的 3 个数, 他们的和一定大于其中任意一个数. **3SUM-closed** 不成立. 因此, 数组至多只能有 2 个正数.

负数同理. 数组至多只能有 2 个负数.

考虑 0 对答案的贡献. 

如果没有 0, 组合有: `- - +` ` - + +` 

有 1 个 0: `- 0 +` 

有 2 个 0: `- 0 0` `0 0 +`

有 3 个 0: `0 0 0`

假设数组已经有 2 个 0, 且已经满足 **3SUM-closed**, 那么再加入 0 也满足 **3SUM-closed**. 所以我们可以去掉多余的 0, 只保留 2 个.

剩下需要判断的数组最多只有 2 + 2 + 2 = 6 个数, 暴力循环判断即可.

### 代码

![image-20220629145724206](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206291457254.png)

![image-20220629145733712](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206291457749.png)

```cpp
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

vector<int> neg,pos,sum;

bool judge(){
	int len=sum.size();
	int ans=0;
	FOR(i,0,len-1){
		FOR(j,i+1,len-1){
			FOR(k,j+1,len-1){
				ans=0;
				FOR(l,0,len-1) if(sum[i]+sum[j]+sum[k]==sum[l]) ans=1;
				if(ans==0) return false;
			}
		}
	}
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		neg.clear();pos.clear();sum.clear();
		int n;cin>>n;
		int zero=0;
		FOR(i,1,n){
			int x;cin>>x;
			if(x<0) neg.push_back(x);
			if(x==0) zero++;
			if(x>0) pos.push_back(x);
		}
		if(neg.size()>2 or pos.size()>2) {cout<<"NO\n";continue;}
		if(zero>2) zero=2;
		for(auto i:neg) sum.push_back(i);
		for(auto i:pos) sum.push_back(i);
		FOR(i,1,zero) sum.push_back(0);
		if(judge()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
```

