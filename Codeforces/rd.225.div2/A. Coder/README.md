https://codeforces.com/contest/384/problem/A

### 标签

构造

### 题意

给定 n, 要求生成一个 n * n 的矩阵, 放入尽可能多的 Coder, 且它们的四个方向上没有 Coder. 输出能放 Coder 的最大数量, 并输出这个矩阵.

### 思路

构造

![ ](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-06-081120.png)

### 代码

![image-20220706161149657](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-06-081149.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int N = 1007;
char ans[N][N];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	int sum=0;
	FOR(i,1,n){
		FOR(j,1,n){
			if(i%2+j%2==2 or i%2+j%2==0) ans[i][j]='C',sum++;
			if(i%2+j%2==1) ans[i][j]='.';
		}
	}
	cout<<sum<<endl;
	FOR(i,1,n){
		FOR(j,1,n) cout<<ans[i][j];
		cout<<endl;
	}
	return 0;
}
```

