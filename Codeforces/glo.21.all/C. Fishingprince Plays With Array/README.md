https://codeforces.com/contest/1696/problem/C

st1=21:57, ed1=22:10

st2=22:25, ed2=null

### 关键词

数组操作

### 题意

给定长度为 n 的数组 a 和整数 m. 有以下 2 个操作:

1. 选择 1 个 a[i], 且 a[i] 可以被 m 整除. 将这个 a[i] 替换为 m 个 a[i]/m.

2. 选择长度为 m 的数列, 且 a[i] = a[i+1] = ... =a[i+m-1], 将其替换为 1 个 m*a[i].

给定长度为 k 的数组 b, 判断能否在任意次操作后将 a 转化为 b.

### 思路

发现操作 1 和操作 2 是互逆的, 且 a -> b 等价于 b -> a.

~~把 a, b 都用操作 2 压缩到最短数列, 然后判断其是否相等即可.~~

把 a, b 都用操作 1 扩展到最长数列, 然后判断其是否相等即可.

由于扩展后数列过长, 会导致 MLE 或 RE, 只需要记录当前的 a[i] 拓展成 num 个 相同的 val, 将连续相同的 val 合并, 判断合并后的两个数组是否相等.

### 代码 (我太拉了)

![image-20220627151609301](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206271516388.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int MAXN=5e4+7;
int n,m,k;

struct node{int val,num;};

vector<node> a(MAXN),b(MAXN);

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		a.clear();
		b.clear();
		cin>>n>>m;
		int val,lena=0,lenb=0;
		FOR(i,0,n-1){
			cin>>val;
			int num=1;
			while(val%m==0 and val){
				num*=m;
				val/=m;
			}
			if(a[lena-1].val==val) a[lena-1].num+=num;
			else a[lena++]=(node){val,num};
		}
		cin>>k;
		FOR(i,0,k-1){
			cin>>val;
			int num=1;
			while(val%m==0 and val){
				num*=m;
				val/=m;
			}
			if(b[lenb-1].val==val) b[lenb-1].num+=num;
			else b[lenb++]=(node){val,num};
		}

		int eq=1;
		if(lena!=lenb) {cout<<"No\n";continue;}
		FOR(i,0,lena-1){
			if(a[i].val!=b[i].val or a[i].num!=b[i].num) {eq=0;break;}
		}
		if(eq==1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
```

