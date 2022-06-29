https://codeforces.com/contest/1698/problem/D

### 标签

数组操作, 对分查找, 交互题

### 题意

本题是交互题.

有一个长度为 n 的数组 a ={1, 2, 3, ... ,n}, n 是正奇数. 裁判程序选择了 (n - 1) / 2 个互不干扰的数对, 交换这 2 个数. 例如, a = {1, 2, 3, 4, 5}, swap(1, 4), swap(3, 5) 后变成 {4, 2, 5, 1, 3}.

交换完成后, 有 1 个数位置不变. 找出这个数.

你可以询问至多 15 次. 每次询问的格式是 `? l r`, 你将得到 a[l], a[l+1], ... ,a[r], 但得到的子数组被升序排序.

当你明确答案后, 输出 `! ans`.

### 思路

(参考官方题解)

注意到 $\log_2{10^4}=13.3<15$, 可以用对分查找解决问题.

结论是当我们获得一个 [l, r] 的子数组, 统计其中有多少个数 a[i] 满足 $a[i] \in [l, r]$,  如果这个数 cnt 是奇数, 那么固定点就在 [l, r] 中, 否则不在.

证明如下:

假定现在有个数 $a[x]=x \in [l, r]$, 它与一个 $a[y]=y \notin [l, r]$ 交换, 那么此时 $a[x] = y \notin[l,r]$, 对 cnt 没有贡献.

假定现在有个数 $a[x]=x \in [l, r]$, 它与一个 $a[y]=y \in [l, r]$ 交换, 那么此时 $a[x] = y \in[l,r]$, cnt += 2.

对于固定点 ans, ans 会使它所在的区间 [l, r] 的 cnt += 1.

所以如果 cnt 使奇数, 那么固定点就在 [l, r] 中. 

证毕.

对于交互题, 需要在每次输出后刷新缓冲区

- `fflush(stdout)` or `cout.flush()` in C++;
- `System.out.flush()` in Java;
- `flush(output)` in Pascal;
- `stdout.flush()` in Python;

其中, C++ 的 `endl` 的作用是 insert newline and flush stream, 不需要再另加 `cout.flush()`.

### 代码

![image-20220629195316161](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206291953214.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

bool judge(int l,int r){
	int x,cnt=0;
	FOR(i,l,r){
		cin>>x;
		if(l<=x and x<=r) cnt++;
	}
	if(cnt%2==1) return true;
	else return false;
}

int ask(int l,int r){
	int mid=(l+r)/2;
	cout<<"? "<<l<<' '<<mid<<endl;
	//cout.flush(); endl已经有flush()的作用
	if(judge(l,mid)){
		if(l==r) return l;
		return ask(l,mid);
	}
	else return ask(mid+1,r);
	return 0;
}

signed main(){
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int ans=ask(1,n);
		cout<<"! "<<ans<<endl;
		//cout.flush();
	}
	return 0;
}
```

