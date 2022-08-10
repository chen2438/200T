### AcWing 243. 一个简单的整数问题2

#### 题目描述

![image-20220809124617747](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208091246838.png)

![image-20220809124625354](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208091246390.png)

#### 代码

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define endl '\n'
using namespace std;

typedef long long LL;
const int N = 100010, M = 350;

int n, m, len;
LL add[M], sum[M];
int bel[N];
int w[N];

void change(int l, int r, int d){
    if(bel[l] == bel[r]) FOR(i,l,r) w[i]+=d, sum[bel[i]]+=d;
    else{
        int i = l, j = r;
        while(bel[i] == bel[l]) w[i] += d, sum[bel[i]] += d, i ++ ;
        while(bel[j] == bel[r]) w[j] += d, sum[bel[j]] += d, j -- ;
        FOR(k,bel[i],bel[j]) sum[k] += len * d, add[k] += d;
    }
}

LL query(int l, int r){
    LL res = 0;
    if (bel[l] == bel[r]) FOR(i,l,r) res += w[i] + add[bel[i]];
    else{
        int i = l, j = r;
        while(bel[i] == bel[l]) res += w[i] + add[bel[i]], i ++ ;
        while(bel[j] == bel[r]) res += w[j] + add[bel[j]], j -- ;
        FOR(k,bel[i],bel[j]) res += sum[k];
    }
    return res;
}

void solve(){
    cin>>n>>m;
    len = sqrt(n);
    FOR(i,1,n) bel[i]=i/len;
    FOR(i,1,n) cin>>w[i];
    FOR(i,1,n) sum[bel[i]]+=w[i];
    string op;
    int l, r, d;
    while (m -- ){
        cin>>op>>l>>r;
        if (op == "C"){
            cin>>d;
            change(l, r, d);
        }
        else cout<<query(l, r)<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}
```

