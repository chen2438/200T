# [Codeforces Round #815 (Div. 2)](https://codeforces.com/contest/1720)

## 提交情况

![image-20220820121001472](https://media.opennet.top/i/2023/01/09/63bb9696c4d57.png)

## 参考

[*Codeforces Round #815* (Div. 2) A - D2](https://zhuanlan.zhihu.com/p/555395807)

[*Codeforces Round #815* (Div. 2) D1 D2(字典树 + dp)](https://zhuanlan.zhihu.com/p/555425330)

## A. Burenka Plays with Fractions

### 标签

构造

### 题意

![image-20220820121117750](https://media.opennet.top/i/2023/01/09/63bb96975ad71.png)

### 思路

![image-20220820121134450](https://media.opennet.top/i/2023/01/09/63bb9697e0d6e.png)

### 代码

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(a) cout<<#a<<"="<<a<<endl
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
#define int long long
using namespace std;

const int N = 2e5+7;

void solve(){
    int a,b,c,d; cin>>a>>b>>c>>d;
    if(a*d==b*c) cout<<0<<endl;
    else if(a==0 or c==0) cout<<1<<endl;
    else if((a*d)%(b*c)==0 or (b*c)%(a*d)==0) cout<<1<<endl;
    else cout<<2<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## B. Interesting Sum

### 标签

贪心

### 题意

![image-20220820121335115](https://media.opennet.top/i/2023/01/09/63bb969857706.png)

### 思路

![image-20220820121346509](https://media.opennet.top/i/2023/01/09/63bb9698c3f6f.png)

这道题我把自己绕进去了，chao！

![image-20220820121607074](https://media.opennet.top/i/2023/01/09/63bb96996e51d.png)

### 代码

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(a) cout<<#a<<"="<<a<<endl
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
#define int long long
using namespace std;

const int N = 2e5+7;
int a[N];

void solve(){
    int n; cin>>n;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    cout<<a[n]+a[n-1]-a[1]-a[2]<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## C. Corners

### 标签

构造

### 题意

![image-20220820121723731](https://media.opennet.top/i/2023/01/09/63bb969a13461.png)

### 思路

![image-20220820121745050](https://media.opennet.top/i/2023/01/09/63bb969a9bbcc.png)

### 代码

与思路略有不同

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(a) cout<<#a<<"="<<a<<endl
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 507;
int a[N][N];

int judge(int x,int y){
    int cnt=0;
    FOR(i,0,1){
        FOR(j,0,1){
            if(!a[x+i][y+j]) cnt++;
        }
    }
    if(cnt>=2) return 1;
    else return 0;
}

void solve(){
    int n,m; cin>>n>>m;
    int cnt=0;
    FOR(i,1,n){
        FOR(j,1,m){
            char c; cin>>c;
            a[i][j]=c-'0';
            if(a[i][j]) cnt++;
        }
    }
    int has_2=0;
    FOR(i,1,n-1){
        FOR(j,1,m-1){
            if(judge(i,j)) has_2=1;
        }
    }
    if(has_2) cout<<cnt<<endl;
    else if(cnt==n*m) cout<<cnt-2<<endl;
    else cout<<max(0,cnt-1)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## D1. Xor-Subsequence (easy version)

### 标签

动态规划

### 题意

![image-20220820122036398](https://media.opennet.top/i/2023/01/09/63bb969b332f1.png)

### 思路

注意 b 数组是 a 的下标序列，我读题的时候以为 b 是 a 的子序列......

![image-20220820122255827](https://media.opennet.top/i/2023/01/09/63bb969bb7c6c.png)

![image-20220820122307130](https://media.opennet.top/i/2023/01/09/63bb969c5af95.png)

限制可以卡到 256 。 

### 代码

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(a) cout<<#a<<"="<<a<<endl
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 3e5+7;
int a[N],f[N];

void solve(){
    int n; cin>>n;
    FOR(i,0,n-1){
        f[i]=1;
        cin>>a[i];
    }
    FOR(i,0,n-1){
        FOR(j,max(0,i-256),i-1){
            if((a[j]^i)<(a[i]^j)) f[i]=max(f[i],f[j]+1);
        }
    }
    int ans=0;
    FOR(i,0,n-1) ans=max(ans,f[i]);
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

