https://codeforces.com/contest/1699/problem/A

### 标签

位运算

### 题意

给定正数 n, 试找到任意 3 个非负整数, 使 a xor b + b xor c + a xor c = n 成立.

### 思路

$公式: a+b=a\ xor\ b+2(a\ and\ b)$

简易证明: 异或是位运算加法, 获取除了进位(2 个 1)以外的1. 或运算获取了进位(2 个 1)的情况, 2 倍的或运算可以模拟进位.

```cpp
a=0101=5
b=0011=3
a+b=1000=8
a^b=0110=6
a&b=0001=1
```

由$公式$, 有

$定理: a\ xor\ b\ 与\ a+b\ 有相同的奇偶性$

这样,  $a\ xor\ b + b\ xor\ c + a\ xor\ c \xlongequal[]{奇偶性} a+b+b+c+a+c=偶数$ .

所以 n 必为偶数.

由于 a xor a = 0, 我们可以令 a = n/2, b = n/2, c = 0, 即为答案.

### 代码

![image-20220705154108616](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-05-074108.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		if(n%2==0) cout<<n/2<<" "<<n/2<<" "<<0<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
```

