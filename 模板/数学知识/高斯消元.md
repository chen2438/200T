### AcWing 883. 高斯消元解线性方程组

#### 题目描述

![image-20220726225638196](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207262256274.png)

![image-20220726225645988](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207262256019.png)

#### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int N = 110;
const double eps = 1e-8;

int n;
double a[N][N];

int gauss(){  // 高斯消元，答案存于a[i][n]中，0 <= i < n
    int c, r;
    for (c = 0, r = 0; c < n; c ++ ){
        int t = r;
        FOR(i,r,n-1)  // 找绝对值最大的行
            if (fabs(a[i][c]) > fabs(a[t][c])) t = i;
        if(fabs(a[t][c]) < eps) continue;
        FOR(i,c,n) swap(a[t][i], a[r][i]);  // 将绝对值最大的行换到最顶端
        ROF(i,n,c) a[r][i] /= a[r][c];  // 将当前行的首位变成1
        FOR(i,r+1,n-1)  // 用当前行将下面所有的列消成0
            if(fabs(a[i][c]) > eps)
                ROF(j,n,c) a[i][j] -= a[r][j] * a[i][c];
        r ++ ;
    }
    if (r < n){
        FOR(i,r,n-1)
            if (fabs(a[i][n]) > eps) return 2; // 无解
        return 1; // 有无穷多组解
    }
    ROF(i,n-1,0)
        FOR(j,i+1,n-1)
            a[i][n] -= a[i][j] * a[j][n];
    return 0; // 有唯一解
}

int main(){
    cin>>n;
    FOR(i,0,n-1)
        FOR(j,0,n)
            cin>>a[i][j];
    int t = gauss();
    if (t == 2) puts("No solution");
    else if (t == 1) puts("Infinite group solutions");
    else{
        FOR(i,0,n-1){
            if (fabs(a[i][n]) < eps) a[i][n] = 0;  // 去掉输出 -0.00 的情况
            printf("%.2lf\n", a[i][n]);
        }
    }
    return 0;
}
```

### AcWing 884. 高斯消元解异或线性方程组

#### 题目描述

![image-20220727100147332](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-27-020147.png)

![image-20220727100155246](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-27-020155.png)

#### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int N = 110;

int n;
int a[N][N];

int gauss(){
    int c, r=0;
    FOR(c,0,n-1){
        int t = r;
        FOR(i,r,n-1) if (a[i][c]) t = i;
        if (!a[t][c]) continue;
        FOR(i,c,n) swap(a[r][i], a[t][i]);
        FOR(i,r+1,n-1)
            if (a[i][c])
                for (int j = n; j >= c; j -- ) a[i][j] ^= a[r][j];
        r ++ ;
    }
    if (r < n){
        FOR(i,r,n-1) if (a[i][n]) return 2;
        return 1;
    }
    ROF(i,n-1,0)
        FOR(j,i+1,n-1)
            a[i][n] ^= a[i][j] * a[j][n];
    return 0;
}

int main(){
    cin >> n;
    FOR(i,0,n-1)
        FOR(j,0,n)
            cin >> a[i][j];
    int t = gauss();
    if (t == 0) FOR(i,0,n-1) cout << a[i][n] << endl;
    else if (t == 1) puts("Multiple sets of solutions");
    else puts("No solution");
    return 0;
}
```

