# [Codeforces Round #809 (Div. 2)](https://codeforces.com/contest/1706)

## 提交情况

![image-20220719143853722](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-19-063854.png)

![image-20220719143902619](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-19-063903.png)

## 参考

[Codeforces Round #809 (Div. 2) A ~ D](https://zhuanlan.zhihu.com/p/543287773)

[Codeforces Round #809 (Div. 2) A - E](https://zhuanlan.zhihu.com/p/543271168)

## A. Another String Minimization Problem

### 标签

构造, 贪心

### 题意

![image-20220719125643427](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-19-045643.png)

### 思路

对于每个 a[i] 每次优先更改前面的, 如果前面已经改过, 再改后面的.

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

//#define int long long
const int N = 1e5+7;
int a[N];
char s[N];

void solve(){
    int n,m; cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,m) s[i]='B';
    FOR(i,1,n){
        int l=a[i], r=m+1-a[i];
        if(r<l) swap(l,r);
        if(s[l]=='B') s[l]='A';
        else s[r]='A';
    }
    FOR(i,1,m) cout<<s[i];
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```



## B. Making Towers

### 标签

构造, 贪心

### 题意

![image-20220719130115643](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-19-050115.png)

### 思路

![image-20220719130142403](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-19-050142.png)

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

//#define int long long
const int N = 1e5+7;
vector<int> p[N];

void solve(){
    int n; cin>>n;
    FOR(i,1,n) p[i].clear();
    FOR(i,1,n){
        int x; cin>>x;
        p[x].push_back(i);
    }
    FOR(i,1,n){
        if(p[i].empty()) {cout<<0<<" "; continue;}
        int cnt=1,pre=p[i][0];
        FOR(j,1,p[i].size()-1){
            if((p[i][j]-pre)%2==1){
                cnt++;
                pre=p[i][j];
            }
        }
        cout<<cnt<<" ";
    }
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```



## C. Qpwoeirut And The City

### 标签

构造, 前缀和

### 题意

![image-20220719125005432](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-19-045005.png)

### 思路

若 n 为奇数, 那么需要增高的就是 2, 4, 6, ... 的这些建筑物, 直接计算即可.

若 n 为偶数, 则有两个连续的位置不增高.

计算全为偶数位置增高的情况的前缀和, 计算全为奇数位置增高的情况的后缀和, 然后遍历分隔点, 找出前缀 + 后缀的最小值.

### 代码

我比赛的时候最小值初始值赋 1e9, 太小了, 可恶啊.

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define int long long
const int N = 1e5+7;
int a[N],pre[N],suf[N];

void solve(){
    memset(pre,0,sizeof pre);
    memset(suf,0,sizeof suf);
    int n; cin>>n;
    FOR(i,1,n) cin>>a[i];
    
    for(int i=2;i<=n-1;i+=2)
        pre[i] += max({0ll,a[i-1]+1-a[i],a[i+1]+1-a[i]});
    FOR(i,1,n) pre[i]=pre[i]+pre[i-1];
    
    if(n%2==1) {cout<<pre[n]<<endl;return;}
    
    for(int i=3;i<=n-1;i+=2)
        suf[i] += max({0ll,a[i-1]+1-a[i],a[i+1]+1-a[i]});
    ROF(i,n,1) suf[i]=suf[i]+suf[i+1];
    
    int pos,min0=1e18;
    FOR(i,1,n) min0=min(min0,pre[i]+suf[i+1]);
    cout<<min0<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## D1. Chopping Carrots (Easy Version)

### 标签

暴力, 二分

### 题意

![image-20220719143441571](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-19-063442.png)

### 思路

![image-20220719143513962](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-19-063514.png)

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

//#define int long long
const int N = 1e5+7;
int a[N];

void solve(){
    int n,k; cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    if(n==1) {cout<<0<<endl;return ;}
    if(k>a[n]) {cout<<0<<endl;return ;}
    int ans=2e9;
    FOR(i,a[n]/k,a[n]/1){
        int cmin=1e9;
        FOR(j,1,n){
            int l=1, r=k;
            while(l<r){
                int mid=(l+r)/2;
                if(a[j]/mid<=i) r=mid;
                else l=mid+1;
            }
            if(a[j]/r>i) {cmin=-1e9;break;}
            cmin=min(cmin,a[j]/r);
        }
        ans=min(ans,i-cmin);
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

