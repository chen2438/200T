https://codeforces.com/contest/1696/problem/D

### 标签

区间最值, 递归

### 题意

给定一个 1 ~ n 的排列 { a[1], a[2], ... , a[n] }, 定义 mn(i, j) = min( a[i ->j ] ), mx(i, j) = max( a[i -> j]).

构建 n 个结点的无向图. 对于每一对 { i, j }, 如果 **(** mn(i, j) == a[i] **and** mx(i, j) == a[j] **)** **or** **(** mn(i, j) == a[j] **and** mx(i, j) == a[i] **)** , (即 a[i], a[j] 是这一段区间的最值), 在结点 **i, j** (不是 a[i], a[j]) 之间添加 1 条长度为 1 的无向边.

找出结点 1 到结点 n 的最短距离. 可以证明最短距离一定存在.

### 思路

(参考官方题解)

定义 dis(1, n) 为结点 1 到 n 的最短距离.

假设 a[i] = n, 且 i ≠ 1, i ≠ n. 由于 a[i] 是整个排列中的最大值, 对于 x < i < y, x 和 y 不可能直接连接. 所以从 1 到 n 必须经过 i. 所以 dis(1, n) = dis(1, i) + dis(i, n).

下面讨论 dis(1, i).

已知 a[i] 是 [1, i] 中的最大元素. 考虑 [1, i] 中的最小元素, 假设它是 a[j] (j < i). 那么 dis(1, i) = dis(1,j) + dis(j, i) =  dis(1,j) + 1.

dis(i,n) 同理.

在代码实现上, 我们不需要求区间最值 (实测用树状数组会 TLE ), 因为需要求的区间的一个端点始终是 1 或 n, 只需要预处理得到 [1, i] (i = 1 -> n) 和 [i, n] (i = 1 -> n) 的最大最小值, 即前缀与后缀的最大最小值.

### 代码

![image-20220628202142743](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202206282021811.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define MAXN (int)2.5e5+7
//#define debug

struct DATA{
    int v,i;//值,下标
    bool operator<(const DATA &x)const{
        return v<x.v;
    }
    bool operator>(const DATA &x)const{
        return v>x.v;
    }
};

struct NODE{
    DATA mi,ma;
};

int n;
DATA v[MAXN];
NODE pre[MAXN],suf[MAXN];

void ValInit(){//预处理前缀,后缀的最大最小值
    pre[1]={ v[1], v[1] };
    suf[n]={ v[n], v[n] };
    FOR(i,2,n){
        pre[i].mi=min(pre[i-1].mi,v[i]);
        pre[i].ma=max(pre[i-1].ma,v[i]);
    }
    ROF(i,n-1,1){
        suf[i].mi=min(suf[i+1].mi,v[i]);
        suf[i].ma=max(suf[i+1].ma,v[i]);
    }
}

int Dis(int l,int r,int k,int todo){//最短距离
    //k=-1找最小, k=1找最大; todo=-1找左边, todo=1找右边
	if(l==r) return 0;
	if(l+1==r) return 1;
	int mid;
    if(todo==-1){//左边一直找左边
        if(k==-1) mid=pre[r].mi.i;
        if(k==1) mid=pre[r].ma.i;
        return Dis(1,mid,-k,-1)+1;
    }
    if(todo==1){//右边一直找右边
        if(k==-1) mid=suf[l].mi.i;
        if(k==1) mid=suf[l].ma.i;
        return 1+Dis(mid,n,-k,1);
    }
    return 0;
}

int DisStart(){
	int mid=pre[n].ma.i;
	return Dis(1,mid,-1,-1)+Dis(mid,n,-1,1);
}

signed main(){
	int T=1;
    #ifndef debug
        cin>>T;
    #endif
	while(T--){
		cin>>n;
		FOR(i,1,n){
			scanf("%d",&v[i].v);
            v[i].i=i;
		}
        ValInit();
		cout<<DisStart()<<'\n';
	}
	return 0;
}
```

