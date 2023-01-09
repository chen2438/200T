

# [CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)](https://codeforces.com/contest/1704)

## 提交情况

![image-20220801215209435](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208012152486.png)

## 参考

[*CodeTON Round 2* (Div. 1 + Div. 2, Rated, Prizes!) A~E](https://zhuanlan.zhihu.com/p/548376193)

## A. Two 0-1 Sequences

### 标签

构造

### 题意



![image-20220801215334414](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208012153441.png)

### 思路

设 1 为字符串开头下标

要求 b[2], b[3], ..., b[m] 与 a[] 的末尾完全一致.

然后如果在 a[] 的前面任意处找到 b[1], 则成功.

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

void solve(){
    int n,m; cin>>n>>m;
    string a,b; cin>>a>>b;
    if(n<m) {cout<<"NO\n";return;}
    int ans=1;
    FOR(i,1,b.size()-1){
        if(b[i]!=a[a.size()-b.size()+i]) ans=0;
    }
    if(ans==0){cout<<"NO\n";return;}
    ans=0;
    FOR(i,0,a.size()-b.size()){
        if(a[i]==b[0]) ans=1;
    }
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## B. Luke is a foodie

### 标签

贪心

### 题意

![image-20220801215909297](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208012159328.png)

### 思路

![image-20220801215932386](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208012159411.png)

### 代码

```cpp
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define endl '\n'
#define int long long
using namespace std;

const int N = 2e5+7;
int a[N];
int l[N],r[N],ml[N],mr[N];

void solve(){
    int n,x; cin>>n>>x;
    FOR(i,1,n){
        cin>>a[i];
        l[i]=a[i]-x;
        r[i]=a[i]+x;
    }
    ml[n]=l[n],mr[n]=r[n];
    int ans=0;
    ROF(i,n-1,1){
        if(r[i]<ml[i+1] or l[i]>mr[i+1]){
            ans++;
            ml[i]=l[i];
            mr[i]=r[i];
            continue;
        }
        ml[i]=maxs(ml[i+1],l[i]);
        mr[i]=mins(mr[i+1],r[i]);
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

## C. Virus

### 标签

贪心

### 题意

![image-20220801220126328](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208012201362.png)

### 思路

优先保护城市数量多的区间，一天保护区间的一端，模拟这个保护的操作即可。

需要注意一些边界情况。

### 代码

```cpp
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define endl '\n'
#define int long long
using namespace std;

const int N = 2e5+7;
int a[N];

struct node{
    int l,r,len;
    bool operator<(const node &y)const{
        return len>y.len;
    }
};

vector<node> s;

void solve(){
    s.clear();
    int n,m; cin>>n>>m;
    FOR(i,1,m) cin>>a[i];
    sort(a+1,a+m+1);
    FOR(i,1,m-1){
        s.push_back({a[i],a[i+1],a[i+1]-a[i]-1});
    }
    s.push_back({a[m],a[1],n-a[m]-1+a[1]});
    sort(s.begin(),s.end());
    int ans=0;
    int day=0;
    for(auto i:s){
        if(i.len<=day*2)break;
        i.len-=day*2;
        if(i.len==2 or i.len==1) ans+=1;
        else ans+=i.len-1;
        day+=2;
    }
    ans=n-ans;
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## D. Magical Array

### 标签

构造

### 题意

![image-20220801220628564](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208012206595.png)

### 思路

![image-20220801220646662](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208012206715.png)

### 代码

```cpp
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define all(a) (a).begin(),(a).end()
#define endl '\n'
#define int long long
using namespace std;

const int N = 1e5+7, M = 3e5+7;
int sum[M];

void solve(){
    int n,m; cin>>n>>m;
    FOR(i,1,n){
        sum[i]=0;
        FOR(j,1,m){
            int x; cin>>x;
            sum[i]+=x*j;
        }
    }
    int mx=*max_element(sum+1,sum+n+1);
    int mi=*min_element(sum+1,sum+n+1);
    cout<<max_element(sum+1,sum+n+1)-sum<<" ";
    cout<<mx-mi<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

