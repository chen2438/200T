# [Codeforces Round #810 (Div. 2)](https://codeforces.com/contest/1711)

## 提交情况

![image-20220725212531320](https://media.opennet.top/i/2023/01/09/63bb9691a8198.png)

## 参考

[*Codeforces Round #810* (Div. 1 + Div. 2) 2A - 2D](https://zhuanlan.zhihu.com/p/545662765)

[*Codeforces Round #810*(Div. 2)(A - C)](https://zhuanlan.zhihu.com/p/545649100)

## A. Perfect Permutation

### 标签

构造

### 题意

![image-20220725213007331](https://media.opennet.top/i/2023/01/09/63bb969240d7a.png)

### 思路

相邻的数互质。

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 2e5+7;

void solve(){
    // 1 2 3 4 5 6 7 8 9
    // 1
    // 2 1
    // 2 3 1
    // 2 3 4 1
    // 2 3 4 5 1
    int n; cin>>n;
    if(n>1)cout<<2<<" ";
    FOR(i,2,n-1) cout<<i+1<<" ";
    cout<<1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## B. Party

### 标签

构造

### 题意

![image-20220725213059484](https://media.opennet.top/i/2023/01/09/63bb9692cb34e.png)

注意只有一对朋友会吃掉一个蛋糕，单个人不会吃蛋糕。

### 思路

![image-20220725213226965](https://media.opennet.top/i/2023/01/09/63bb96938f2ef.png)

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define PII pair<int,int>
#define endl '\n'
// #define int long long
using namespace std;

const int N = 2e5+7;
int a[N],e[N];
PII p[N];

void solve(){
    mem(e);
    int n,m; cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,m){
        int x,y; cin>>x>>y;
        p[i]={x,y};
        e[x]++,e[y]++;
    }
    if(m%2==0) {cout<<"0\n"; return ;}
    int ans=2e9;
    FOR(i,1,n) if(e[i]%2) ans=min(ans,a[i]);
    FOR(i,1,m){
        int x=p[i].first, y=p[i].second;
        if(e[x]%2==0 and e[y]%2==0)
            ans=min(ans,a[x]+a[y]);
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

## C. Color the Picture

### 标签

构造

### 题意

![image-20220725213401285](https://media.opennet.top/i/2023/01/09/63bb969435019.png)

![image-20220725213431857](https://media.opennet.top/i/2023/01/09/63bb9694b8ae1.png)

### 思路

![image-20220725213454697](https://media.opennet.top/i/2023/01/09/63bb969557296.png)

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define PII pair<int,int>
#define endl '\n'
#define int long long
using namespace std;

const int N = 2e5+7;
int a[N],kn[N],km[N],oddn,oddm;

void solve(){
    oddn=0,oddm=0;
    int n,m,k; cin>>n>>m>>k;
    FOR(i,1,k) cin>>a[i];
    int sumn=0,summ=0;
    FOR(i,1,k){
        kn[i]=a[i]/n;
        if(kn[i]==1) kn[i]=0;
        if(kn[i]>=3) oddn=1;
        sumn+=kn[i];
        
        km[i]=a[i]/m;
        if(km[i]==1) km[i]=0;
        if(km[i]>=3) oddm=1;
        summ+=km[i];
    }
    
    if(sumn<m and summ<n) {cout<<"No\n";return;}
    if(sumn>=m){
        if(m%2 and oddn) {cout<<"Yes\n";return;}
        if(m%2==0) {cout<<"Yes\n";return;}
    }
    if(summ>=n){
        if(n%2 and oddm) {cout<<"Yes\n";return;}
        if(n%2==0) {cout<<"Yes\n";return;}
    }
    cout<<"No\n"; return;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

