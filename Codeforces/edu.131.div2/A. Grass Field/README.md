https://codeforces.com/contest/1701/problem/A

### 标签

简单构造

### 题意

给定一个 2 * 2 的 01 矩阵，每次操作可以将一行和一列置零。问至少操作几次，才能使矩阵均为0。

### 思路

见代码

### 代码

![image-20220709131126740](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-09-051127.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int sum=0;
		FOR(i,1,4){
			int x;cin>>x;sum+=x;
		}
		if(sum==0)cout<<0<<endl;
		if(sum>=1 and sum<=3)cout<<1<<endl;
		if(sum==4)cout<<2<<endl;
	}
	return 0;
}
```

