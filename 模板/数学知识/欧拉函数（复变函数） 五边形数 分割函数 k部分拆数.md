# 欧拉函数（复变函数） 五边形数 分割函数 k部分拆数

## 欧拉函数（复变函数）

<img src="https://media.opennet.top/i/2023/01/09/63bb97516b95c.jpg" alt="image-20220325224715174" style="zoom:50%;" />

将这个式子展开

<img src="https://media.opennet.top/i/2023/01/09/63bb9751d8e50.jpg" alt="image-20220325224807676" style="zoom:50%;" />

其中 $x$ 的次数，$\frac{3k^2-k}{2}$，为[广义五边形数](https://zh.wikipedia.org/wiki/廣義五邊形數)

将得到的所有项按升幂排列，得到：

<img src="https://media.opennet.top/i/2023/01/09/63bb975259e45.jpg" alt="image-20220325225231363" style="zoom:50%;" />

## 分割函数

**定义**：将正整数 $n$ 拆分为若干个正整数的和（允许同一个数使用多次，这里的拆分是无序的，即 1+2 和 2+1 等价）的方案数。

欧拉函数的倒数是**划分数（分割函数）**的**生成函数**：

<img src="https://media.opennet.top/i/2023/01/09/63bb9752e00ca.jpg" alt="image-20220325232231460" style="zoom:50%;" />

其中 $p(i)$ 为 $i$ 的分割函数

有

<img src="https://media.opennet.top/i/2023/01/09/63bb975387503.jpg" alt="image-20220325234204155" style="zoom:50%;" />

展开得到递推式

<img src="https://media.opennet.top/i/2023/01/09/63bb975430335.jpg" alt="image-20220325234251753" style="zoom:50%;" />

### 分割函数的代码实现 $O(n\sqrt{n})$

[P6189 [NOI Online #1 入门组] 跑步](https://www.luogu.com.cn/problem/P6189)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn (1e5+7);
const int INF (1<<30);

long long f[maxn];

inline int a(int x){
    return (3*x*x-x)/2;
}

int main(){
    int n,p;
    cin>>n>>p;
    f[0]=1;
    FOR(i,1,n){
        FOR(j,1,INF){
            int x=a(j),y=a(-j);
            if(x<=i) f[i]=((f[i]+(j&1?1:-1)*f[i-x])%p+p)%p;
            //f(i)=f(i)+(-1)^(j+1)*f(i-x)
            if(y<=i) f[i]=((f[i]+(j&1?1:-1)*f[i-y])%p+p)%p;
            if(x>i or y>i) break;
        }
    }
    cout<<f[n];
    return 0;
}
```



## 五边形数

**五边形数**是能排成[五边形](https://zh.wikipedia.org/wiki/五邊形)的[多边形数](https://zh.wikipedia.org/wiki/多邊形數)。

<img src="https://media.opennet.top/i/2023/01/09/63bb9754c648f.jpg" alt="image-20220325230706580" style="zoom:50%;" />

通项公式：<img src="https://media.opennet.top/i/2023/01/09/63bb975553934.jpg" alt="image-20220325231030671" style="zoom:50%;" />

**广义五边形数**的公式和五边形数相同，只是 n 可以为负数和零，**n 依序为0, 1, -1, 2, -2, 3, -3, 4...**，广义五边形数也可以用下式表示：

<img src="https://media.opennet.top/i/2023/01/09/63bb9755baf47.jpg" alt="image-20220325231233477" style="zoom:50%;" />

**n 依序为0, 1, 2, 3, 4, 5, 6, 7, 8...**

其产生的数列如下：

0, 1, 2, 5, 7, 12, 15, 22, 26...

## k部分拆数

将 $n$ 分成恰有 $k$ 个部分的分拆，称为 $k$ 部分拆数，记作 $p(n,k)$。

**递推式**：$p(n,k)=p(n-1,k-1)+p(n-k,k)$

例题：计算 $k$ 部分拆数 $p(n,k)$。多组输入，其中 $n$ 上界为 $10000$，$k$ 上界为 $1000$，对 $1e9+7$ 取模。
```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int mod=1e9+7;
int p[10005][1005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k;
    while(cin>>n>>k) {
        memset(p,0,sizeof(p));
        p[0][0]=1;
        FOR(i,1,n){
            FOR(j,1,k)
                if(i-j>=0) p[i][j]=(p[i-j][j]+p[i-1][j-1])%mod;
        }
        cout<<p[n][k]<<'\n';
    }
}
```
