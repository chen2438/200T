https://codeforces.com/contest/381/problem/C

### 标签

数组操作, 递归, 二分查找

### 题意

对于序列 a, 有 2 种操作.

1. 在序列末尾添加 1 个数.
2. 将序列 a[1] -> a[l] 复制 c 倍, 添加到数组末尾.

给定 m 次操作和 n 次询问, 每次询问输出序列对应下标的值.

### 思路

生成的序列可能很大, 但输出的数组只有 1e5.

最长的序列长度有 (1+1e5)*1e5/2=5e9, 不能直接存.

且输入的数组下标可能爆 int (but 在我的代码里, int 会导致 TLE, 而不是 WA 或 RE).

![image-20220703202200529](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207032022567.png)

发现只有操作 1 对序列的数据增加有实际贡献, 即所有的数都来源于操作 1.

我们记录下每一次操作, 得到该次操作对应的最终序列的区间.

这样, 对于每一次询问, 我们可以通过遍历/二分查找每个操作, 得出哪个操作作用于这个询问的下标.

如果发现这个操作正好是操作 1, 那么可以直接返回数值.

如果是操作 2, 那么可以通过操作 2 的信息向前递归, 直到找到操作 1.

### 代码

![image-20220703204218143](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207032042175.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using ll=long long;
//#define ll int
const int N = 1e5+7;
int m;
struct node{ll o,L,R,x,l,c;}p[N];
 
int search(ll pos,int l,int r){
	if(l==r) return l;
	int mid=(l+r)/2;
	if(p[mid].L<=pos and pos<=p[mid].R) return mid;
	if(pos<p[mid].L) return search(pos,l,mid-1);
	if(p[mid].R<pos) return search(pos,mid+1,r);
	return -1;
}
 
int ask(ll pos){
	ll i=search(pos,1,m);
	if(p[i].o==1) return p[i].x;
	else{
		int npos=(pos-(p[i].L-1))%p[i].l;
		if(npos==0) npos=p[i].l;
		return ask(npos);
	}
	return -1;
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>m;
	ll o,L,R,x,l,c;
	FOR(i,1,m){
		cin>>o;
		if(o==1){
			cin>>x;
			L=p[i-1].R+1, R=L, l=0, c=0;
		}
		if(o==2){
			cin>>l>>c;
			L=p[i-1].R+1, R=L+l*c-1, x=0;
		}
		p[i]={o,L,R,x,l,c};
	}
	int n;cin>>n;
	while(n--){
		ll pos;cin>>pos;
		cout<<ask(pos)<<' ';
	}
	return 0;
}
```

