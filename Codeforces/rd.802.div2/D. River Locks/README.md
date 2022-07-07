## D. River Locks

https://codeforces.com/contest/1700/problem/D

### 标签

二分, 贪心

### 题意

有 n 个水库, 当水库满时, 第 i 个水库可以向第 i + 1 个水库倒水(瞬间完成), 每个水库的容量是 v[i], 依次降序. 每个水库有一个管道连接. 管道打开时每秒传输 1 升水给水库. 最后一个水库会将多余的水瞬间传递到河.

你需要填满所有水库. 

有 q 次询问, 每次询问时所有管道关闭, 水库清空. 你需要回答最少需要同时打开多少个管道以在 t 时间内填满所有水库.

若无法填满, 输出 -1.

### 思路

先求填满所有水库的最短时间. 

定义 pre[i] 为 v[i] 的前缀和.

为了填满第 i 个水库, 必须消耗 pre[i] / i 的时间, 填满所有水库所需要的最小时间取决于最大的 pre[i] / i.

每次询问, 小于最短时间的 t 直接输出 -1.

接下来求最少管道数.

由于 v[1] 只能由第 1 根管道填满, 同时避免最后 1 个水库溢出到河里浪费, 应该优先选择打开上游的管道.

答案应该是满足 $实际时间 =\frac{ pre[n]}{ ans} <= t$ 的最大实际时间对应的最小 ans.

二分查找答案即可.

### 代码

![image-20220707103559657](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-07-023600.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int N = 2e5+7;
int n,m;
double v[N],pre[N];

double MinTime(){
	double ans=0;
	FOR(i,1,n){
		ans=max(ans,pre[i]/(1.0*i));
	}
	return ans;
}//为了填满第i个水库, 必须消耗pre[i]/i的时间
//填满所有水库所需要的最小时间取决于最大的pre[i]/i

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	FOR(i,1,n){
		cin>>v[i];
		pre[i]=pre[i-1]+v[i];
	}
	double mt=MinTime();
	cin>>m;
	while(m--){
		int t;cin>>t;
		if(t<mt) {cout<<-1<<endl;continue;}
		int l=1,r=n;
		//要l=r尽可能小, 但满足实际时间=pre[n]/r<=t, 
		while(l<r){
			int mid=(l+r)/2;
			if(pre[n]/(mid*1.0)<=t) r=mid;
			//考虑mid不满足条件时应该往哪半边找, 找的区间不能包含mid
			else l=mid+1; 
		}
		cout<<r<<endl;
	}
	return 0;
}
```

