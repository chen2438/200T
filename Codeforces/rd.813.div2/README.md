# [Codeforces Round #813 (Div. 2)](https://codeforces.com/contest/1712)

## 参考

[*Codeforces Round #813* (Div. 2) A - E2](https://zhuanlan.zhihu.com/p/553529151)

## 提交记录

## A. Wonderful Permutation

### 标签

构造

### 题意

![image-20220814214933319](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208142149357.png)

### 代码

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 2e5+7;
int a[N];

void solve(){
    int n,k; cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    int ans=0;
    FOR(i,1,k) if(a[i]>k) ans++;
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## B. Woeful Permutation

### 标签

构造

### 题意

![image-20220814215056446](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208142150477.png)

### 思路

![image-20220814215117136](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208142151163.png)

### 代码

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 2e5+7;
int a[N];

void solve(){
    int n; cin>>n;
    FOR(i,1,n) a[i]=i;
    if(n%2==0){
        for(int i=1;i+1<=n;i+=2){
            swap(a[i],a[i+1]);
        }
    }
    else{
        for(int i=2;i+1<=n;i+=2){
            swap(a[i],a[i+1]);
        }
    }
    FOR(i,1,n) cout<<a[i]<<" ";
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## C. Sort Zero

### 标签

构造

### 题意

![image-20220814215315177](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208142153216.png)

### 思路

若两个相同数字不相邻，那这两个数字的区间全为0。

0的前面必须为0。最后再从后往前扫检查后缀有序。

![image-20220814215532362](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208142155406.png)

### 代码

代码写的有点长了，有更简洁的方案。

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 2e5+7;
int a[N];

struct node{
    int l,r;
    bool operator<(const node &y)const{
        return r>y.r;
    }
};

unordered_map<int, int> mp1,mp2;
vector<node> sec,uni;
vector<int> g[N];

void solve(){
    sec.clear();
    uni.clear();
    int n; cin>>n;
    FOR(i,0,n) g[i].clear();
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) g[a[i]].push_back(i);
    FOR(i,1,n){
        int glen=g[i].size();
        if(glen>=2){
            if(g[i][glen-1]-g[i][0]+1==glen) continue;
            sec.push_back({g[i][0],g[i][glen-1]});
        }
    }
    int ans=0;
    sort(sec.begin(),sec.end());
    int ed;
    if(sec.size()) ed=sec[0].r;
    else ed=0;
    FOR(i,1,ed){
        if(g[a[i]].size()){
            ans++;
            g[a[i]].clear();
        }
    }
    int ed2=0;
    ROF(i,n,ed+1+1){
        if(a[i-1]>a[i]){
            ed2=i-1;
            break;
        }
    }
    FOR(i,ed+1,ed2){
        if(g[a[i]].size()){
            ans++;
            g[a[i]].clear();
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

