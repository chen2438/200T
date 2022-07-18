# [Codeforces Round #808 (Div. 2)](https://codeforces.com/contest/1708)

## 提交情况

![image-20220717150532870](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-17-070533.png)

![image-20220717150543715](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-17-070543.png)

好难, 我太拉了

## 参考

[Codeforces Round #808 (Div. 2) A - D](https://zhuanlan.zhihu.com/p/542530019)

[Codeforces Round #808 (Div. 1 + Div. 2) A - D](https://zhuanlan.zhihu.com/p/542519622)

[Codeforces Round #808 (Div. 2) D(暴力)](https://zhuanlan.zhihu.com/p/542553012)

## A. Difference Operations

### 标签

构造, 约数

### 题意

给一个数组，定义一种操作使 a[i] 变成 a[i] - a[i - 1] ，问能否把除了a[1]以外的数删成 0.

### 思路

可以发现, a[2] 是 a[1] 的倍数, a[3] 是 a[2] - k*a[1] 的倍数.

a[3] 同时也是 a[1] 的倍数.

以此类推, a[i] 都是 a[1] 的倍数.

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int N = 107;
int a[N];

void solve(){
    int n;cin>>n;
    FOR(i,1,n) cin>>a[i];
    int ans=1;
    FOR(i,2,n) if(a[i]%a[1]!=0){ans=0;break;}
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
```

## B. Difference of GCDs

### 标签

构造, 最大公约数

### 题意

给定一个三个数，n,l,r，问能否构造一个数组1 - n，使得每一个位置上的数 a[i] 与该位置的坐标 i 的 gcd 各不相同，要求所有数在[l, r]的范围内，输出任意一个符合条件的数组，无解输出NO.

### 思路

由于

$gcd(a,b) \leq min(a, b)$ 

$gcd(a,ka) = a$

所以

 $gcd(a_i,i)=i$

因此我们只需要判断[l, r]中有没有 i 的倍数即可.

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int N = 1e5+7;
int a[N];

void solve(){
    memset(a,0,sizeof a);
    int n,l,r; cin>>n>>l>>r;
    int ans=1;
    FOR(i,1,n){
        if(l%i==0) a[i]=l;
        else if(r%i==0) a[i]=r;
        else{
            int k1=l/i,k2=r/i;
            if(k1==k2) {ans=0;break;}
            a[i]=i*k2;
        }
    }
    if(ans==0){cout<<"NO\n";return;}
    cout<<"YES\n";
    FOR(i,1,n) cout<<a[i]<<" ";
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
```

## C. Doremy's IQ

### 标签

构造, 贪心

### 题意

有 n 场测试, 每场测试难度为 a[i], 你的初始智商为 q, 若 q >= a[i], 则可以接受测试, 否则, 可以消耗 1 点智商接受测试, 或不接受测试(不消耗智商).

求参加最多测试的方案.

### 思路

#### 解释1

![image-20220717131632157](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-17-051632.png)

#### 解释2

![image-20220717131831835](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-17-051832.png)

### 代码

比赛的时候想用 DP, 搞了半天搞不出来...

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int N = 1e5+7;
int a[N];
int ans[N],qmin[N];

void solve(){
    mem(a),mem(qmin),mem(ans);
    int n,q;
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    qmin[n]=1;
    ROF(i,n-1,1){
        if(a[i]<=qmin[i+1]) qmin[i]=qmin[i+1];
        else qmin[i]=qmin[i+1]+1;
    }
    FOR(i,1,n){
        if(qmin[i]<=q){
            FOR(j,i,n) ans[j]=1;
            break;
        }
        else if(a[i]<=q) ans[i]=1;
        else ans[i]=0;
    }
    FOR(i,1,n) cout<<ans[i];
    cout<<endl;
    
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
```

## D. Difference Array

### 标签

构造, 差分, 暴力

### 题意

![image-20220717150140412](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-17-070140.png)

### 思路

#### 解释1

![image-20220717150214875](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-17-070215.png)

#### 解释2

![image-20220717150245731](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-17-070246.png)

**重点是忽略掉 差分并排序后产生的大量的连续 0.**

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int N = 1e5+7;
vector<int> a(N),b(N);

void solve(){
    int n; cin>>n;
    FOR(i,1,n) cin>>a[i];
    int l1=0,l2=0;
    while(l1<n-1){
        sort(a.begin()+l1,a.begin()+n+1);
        if(a[n]==0) break;
        FOR(i,l1,n-1){
            if(a[i]!=0) break;
            if(a[i+1]!=0){l1=i;break;}
        }
        l2++;
        l1=max(l1,l2);
        ROF(i,n,l1+1) a[i]=a[i]-a[i-1];
        a[l1]=0;
    }
    cout<<a[n]<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
```

