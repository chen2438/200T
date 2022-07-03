https://codeforces.com/contest/381/problem/A

### 标签

模拟, 数组操作

### 题意

有 n 张牌, 所有牌上的数字互不相同. 在一个回合中, 可以拿最左边或最右边的牌. 当没有牌可拿时, 游戏结束. 拥有最大数字总和的玩家胜利.

Sereja 和 Dima 在游戏中都倾向选择数字较大的牌. 

试确定 2 个人最后的分数.

### 思路

暴力模拟

### 代码

![image-20220703204338937](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207032043967.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

long long a[1007],ans[3];

void game(int l,int r,int player){
	if(l==r) {ans[player]+=a[l];return ;}
	if(a[l]<a[r]) {ans[player]+=a[r];r--;}
	else {ans[player]+=a[l];l++;}
	game(l,r,player^1);//0 -> 1, 1 -> 0
}

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	FOR(i,1,n) cin>>a[i];
	game(1,n,0);
	cout<<ans[0]<<' '<<ans[1]<<endl;
	return 0;
}
```

