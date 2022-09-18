# [Codeforces Round #816 (Div. 2)](https://codeforces.com/contest/1715)

## 提交情况

![image-20220826155024467](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-08-26-075025.png)

## 参考

[*Codeforces Round #816* (Div. 2) D(贪心)](https://zhuanlan.zhihu.com/p/556088458)

[*Codeforces Round #816* (Div. 2) A - D](https://zhuanlan.zhihu.com/p/556071741)

[*Codeforces Round #816* (Div. 2) A - D](https://zhuanlan.zhihu.com/p/556066621)

## A. Crossmarket

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

const int N = 2e5+7;
int a[N];

void solve(){
    int n,m; cin>>n>>m;
    if(n==1 and m==1) cout<<0<<endl;
    else cout<<max(0,min(n+2*m-2,m+2*n-2))<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## B. Beautiful Array

### 标签

构造

### 题意

![image-20220826155342173](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-08-26-075342.png)

### 思路

![image-20220826155352235](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-08-26-075352.png)

### 代码

比赛时丑陋的 if-else 代码

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
    int n,k,b,s; cin>>n>>k>>b>>s;
    if(k*b<=s and s<=k*b+n*(k-1)){
        int rev=s-k*b,is_first=1;
        FOR(i,1,n){
            if(is_first){
                is_first=0;
                if(rev-(k-1)>0){
                    rev-=k-1;
                    cout<<k*b+k-1<<" ";
                }
                else{
                    cout<<k*b+rev<<" ";
                    rev=0;
                }
                continue;
            }
            if(rev-(k-1)>0){
                rev-=k-1;
                cout<<k-1<<" ";
            }
            else{
                cout<<rev<<" ";
                rev=0;
            }
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## C. Monoblock

### 标签

构造

### 题意

![image-20220826155553587](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-08-26-075554.png)

### 思考过程

比赛时很快想到有 O(能过) 的修改与查询, 于是要想一种 O(能过) 的初始化总价值的算法.

通过模拟样例可得 O(n) 的线性递推总价值的算法. (图为当时草稿)

![image-20220826161702856](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-08-26-081703.png)

即

```cpp
    sum=f[1]=1;
    FOR(i,2,n){
        f[i]=f[i-1]+(a[i-1]!=a[i])*(i-1)+1;
        sum+=f[i];
    }
```

思路就是用第 i 位去拓展 f[i-1], 具体模拟一下就明白了.

在修改与查询时, 根据修改的信息推导 sum 的变化. 

推导的过程和初始化的方法类似, 就是条件判断有点麻烦.

### 思路

这里初始化用的是后缀, 我用的是前缀.

![image-20220826162244270](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-08-26-082244.png)

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
int a[N],f[N],pre[N];

void solve(){
    int n,m; cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    int ans=1,sum;
    sum=f[1]=1;
    FOR(i,2,n){
        f[i]=f[i-1]+(a[i-1]!=a[i])*(i-1)+1;
        sum+=f[i];
    }
    while(m--){
        int i,x; cin>>i>>x;
        if(a[i]==x) {cout<<sum<<endl; continue;}
        if(a[i]==a[i-1] and x!=a[i-1]) sum+=(n-i+1)*(i-1);
        else if(a[i]!=a[i-1] and x==a[i-1]) sum-=(n-i+1)*(i-1);
        if(a[i]==a[i+1] and x!=a[i+1]) sum+=(n-i)*i;
        else if(a[i]!=a[i+1] and x==a[i+1]) sum-=(n-i)*i;
        a[i]=x;
        cout<<sum<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}
```

## D. 2+ doors

### 标签

图论, 贪心, 位运算

### 题意

![image-20220826161902742](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-08-26-081903.png)

### 思路

[*Codeforces Round #816* (Div. 2) D(贪心)](https://zhuanlan.zhihu.com/p/556088458)

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

const int INF = ((1<<30)-1);
const int N = 1e5+7;

struct EDGE{
    int j,x;
};

int a[N],fix[N];
vector<EDGE> g[N];

void solve(){
    int n, q; cin>>n>>q;
    FOR(i,1,n){
        a[i]=INF;//全部初始化为1
        fix[i]=0;
        g[i].clear();
    }
    while(q--){
        int l,r,x; cin>>l>>r>>x;
        if(l==r){
            a[r]=x;
            fix[r]=1;//固定不动
            continue;
        }
        g[l].push_back({r,x});
        g[r].push_back({l,x});
        FOR(i,0,29){
            if((x>>i) & 1) continue;
            //那么x的第i位是0
            if((a[l]>>i) & 1) a[l]^=(1<<i);
            if((a[r]>>i) & 1) a[r]^=(1<<i);
        }
    }
    ROF(k,29,0){
        FOR(i,1,n){
            if(fix[i]) continue;
            if(!((a[i]>>k) & 1)) continue;
            int has_zero=0;
            for(auto T:g[i]){
                int j=T.j,x=T.x;
                if((x>>k) & 1){
                    //需要a[i],a[j]第k位上至少有1个1
                    if(((a[j]>>k) & 1)==0){
                        has_zero=1;
                        break;
                    }
                }
            }
            //有0,那a[i]的第k位必须为1
            //否则贪心地赋0
            if(!has_zero) a[i]^=(1<<k);
        }
    }
    FOR(i,1,n) cout<<a[i]<<" ";
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}
```

