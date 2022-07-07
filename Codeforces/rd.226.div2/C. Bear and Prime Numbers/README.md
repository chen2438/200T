https://codeforces.com/contest/385/problem/C

### 标签

素数, 条件欺骗

### 题意

给定长度为 n 的数组 x 和 m 次询问, 每次询问 l, r.

~~定义 f(p) 是数组 x 内能被 p 整除的数的数量.~~

定义 f(p) 是数组 x 内 p 的倍数的数量.

定义 S(l, r) 是 [l, r] 内的素数.

每次询问的答案是 $\sum_{p \in S(l,r)} f(p)$

### 思路

注意 n<=1e6, x[i]<=1e7, r<=2e9

由于大于 1e7 的素数对答案没有贡献, 所以实际的数据范围只有 1e7.

我们先用线性筛素数把 1 ~ 1e7 的素数筛出来.

读入的 x[i] 用一个桶 buck[] 存, buck[x[i]] 存的是相同 x[i] 的数量.

遍历筛出来的素数, 对于每个素数, 如果它的倍数在 x[i] 存在, 那么 xp[素数的值] += buck[素数的倍数].

这样, xp[] 就存了每个素数对应的 f(p).

最后把 xp[] 做一个前缀和, 方便区间求和, 输出答案.

### 代码

![image-20220707210657194](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207072106244.png)

![image-20220707210705934](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207072107984.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define ll long long
//const int N = 1e6+7;
const int X = 1e7+7;

int buck[X];
int n,m;

int prime[X], cnt;//prime[i]存第i个素数
bool isprime[X];

int get_prime(int n){
    for (int i = 2; i <= n; i ++ ){
        if (!isprime[i]) prime[ ++cnt ] = i;
        for (int j = 1; prime[j] <= n / i; j ++ ){
            isprime[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }
    return cnt;//返回[1,n]中素数的个数
}

int xp[X],pre[X];

void init(){
	FOR(i,1,cnt){
		for(int j=prime[i];j<=1e7;j+=prime[i]){
			xp[prime[i]]+=buck[j];
		}
	}
	FOR(i,1,1e7) pre[i]=pre[i-1]+xp[i];
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	int x;
	FOR(i,1,n) {cin>>x; buck[x]++;}
	cin>>m;
	get_prime(1e7);
	init();
	while(m--){
		int l,r;cin>>l>>r;//l,r<=2e9
		if(l>1e7) {cout<<0<<endl;continue;}
		if(r>1e7) r=1e7;
		cout<<pre[r]-pre[l-1]<<endl;
	}
	return 0;
}
```

