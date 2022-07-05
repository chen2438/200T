https://codeforces.com/contest/1699/problem/B

### 标签

找规律

### 题意

给定偶数 n 和 m, 找到一个 n 行 m 列的 01 矩阵, 使得矩阵里的每个元素有且仅有 2 个不同的(4 个方向上的)相临元素.

### 思路

找规律

![img](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-05-075312.png)

### 代码

![image-20220705155353433](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-05-075353.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int a[100][100];

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,m;cin>>n>>m;
		memset(a,0,sizeof a);
		a[1][1]=1;//a[1][2]=a[2][1]=0;
		FOR(j,3,m){
			if(a[1][j-2]!=a[1][j-1]) a[1][j]=a[1][j-1];
			else a[1][j]=a[1][j-1]^1;
		}
		FOR(j,1,m) a[2][j]=a[1][j]^1;
		FOR(j,1,m){
			FOR(i,3,n){
				if(a[i-2][j]!=a[i-1][j]) a[i][j]=a[i-1][j];
				else a[i][j]=a[i-1][j]^1;
			}
		}
		FOR(i,1,n){
			FOR(j,1,m) cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
```

