https://codeforces.com/contest/1700/problem/A

### 标签

构造

### 题意

给定 $n\times m$ 的矩阵, $a[i][j]=(i-1)\times m+j$. 每次只能往右或者下移动，问从左上角到右下角，经过的位置的和的最小值.

### 思路

走第一行、最后一列.

$ans=\frac{m(m+1)}{2}+m \times (\frac{n(n+1)}{2}-1)$.

### 代码

![image-20220706092359960](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-06-012400.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int a,b;cin>>a>>b;
    cout<<a+b<<endl;
    cout<<(a^b) + 2*(a&b);
    return 0;
}
```

