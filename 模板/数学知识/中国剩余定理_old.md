### 定理

![image-20220726215359910](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207262153967.png)

注意 $m_1, m_2, ... , m_n$ 必须满足两两互质.

### 算法流程

![image-20220726221601696](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207262216726.png)

### 模板

```cpp
// oi-wiki version
LL CRT(int k, LL* a, LL* r) {
  LL n = 1, ans = 0;
  for (int i = 1; i <= k; i++) n = n * r[i];
  for (int i = 1; i <= k; i++) {
    LL m = n / r[i], b, y;
    exgcd(m, r[i], b, y);  // b * m mod r[i] = 1
    ans = (ans + a[i] * m * b % n) % n;
  }
  return (ans % n + n) % n;
}
```



### AcWing 204. 表达整数的奇怪方式

#### 题目描述

![image-20220726221252427](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207262212464.png)

![image-20220726221301502](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207262213533.png)

#### 代码

并没有用到中国剩余定理，需要自己推导。

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    int n; cin >> n;
    LL x = 0, m1, a1;
    cin >> m1 >> a1;
    n--;
    while (n -- ){
        LL m2, a2;
        cin >> m2 >> a2;
        LL k1, k2;
        LL d = exgcd(m1, m2, k1, k2);
        if ((a2 - a1) % d) {x = -1; break;}
        k1 *= (a2 - a1) / d;
        k1 = (k1 % (m2/d) + m2/d) % (m2/d);
        x = k1 * m1 + a1;
        LL m = abs(m1 / d * m2);
        a1 = k1 * m1 + a1;
        m1 = m;
    }
    if (x != -1) x = (a1 % m1 + m1) % m1;
    cout << x << endl;
    return 0;
}
```

