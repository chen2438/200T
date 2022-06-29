https://codeforces.com/contest/1698/problem/A

### 标签

位运算

### 题意

给定 n - 1 个数, 让 x 等于这 n - 1 个数依次 **按位异或** 的结果, 即 x = a[1] ^ a[2] ^a[3] ^ ... ^ a[n - 1].

现在将 x 放入这 n - 1 个数中并打乱, 找出哪个数是 x.

若有多个 x, 输出任意一个.

### 思路

**根据官方题解, 数组中的任意数都可以是 x, 只要任意输出一个数即可.**

以下是我在比赛时的推导.

由于按位异或运算有交换律(a ^ b ^ c = a ^ c ^b), 我们可以把所有数按位异或得到 sum.

我们可以通过对 sum 再次异或得到异或之前的两个数. a ^ b = c, c ^ a = b, c ^ b = a.

然后遍历这 n 个数, 如果 sum ^ x == x, 输出 x 即可. (a[1] 就满足条件)

### 代码

比赛时我把 `sum ^ x == x` 写成 `sum | x == x` 但也通过了. 事后发现是误打误撞写对了.

标准答案:

![image-20220629103159188](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206291031218.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int x;
		FOR(i,1,n) cin>>x;
		cout<<x<<'\n';
	}
	return 0;
}
```

我的答案:

![image-20220629102003120](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206291020162.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int a[1000];

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int sum=0;
		FOR(i,1,n){
			cin>>a[i];
			sum^=a[i];
		}
		FOR(i,1,n){
			if((sum ^ a[i]) == a[i]){
				cout<<a[i]<<'\n';
				break;
			}
		}
	}
	return 0;
}
```

