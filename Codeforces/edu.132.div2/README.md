# [Educational Codeforces Round 132 (Rated for Div. 2)](https://codeforces.com/contest/1709)

## 提交情况

![image-20220722111015251](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-22-031015.png)

## 参考

[Educational Codeforces Round 132 (Rated for Div. 2) A - E](https://zhuanlan.zhihu.com/p/544680336)

## A. Three Doors

### 标签

模拟

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
// #define int long long
using namespace std;

const int N = 1e5+7;

bool solve(){
    int a[10]={0},b[10]={0};
    FOR(i,0,3) {cin>>a[i];b[a[i]]++;}
    FOR(i,0,3){
        if(b[i]!=1)return false;
    }
    if(a[a[0]]!=0 and a[a[a[0]]]!=0)return true;
    else return false;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--){
        if(solve()) puts("YES");
        else puts("NO");
    }
    return 0;
}
```



## B. Also Try Minecraft

### 标签

前缀和

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e5+7;
int a[N],b1[N],b2[N],pre1[N],pre2[N];

void solve(){
    int n,m; cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n){
        if(a[i-1]>a[i]) b1[i]=a[i-1]-a[i];
        else b2[i]=a[i]-a[i-1];
    }
    FOR(i,1,n){
        pre1[i]=pre1[i-1]+b1[i];
        pre2[i]=pre2[i-1]+b2[i];
    }
    FOR(i,1,m){
        int l,r; cin>>l>>r;
        if(l<r) cout<<pre1[r]-pre1[l]<<endl;
        else cout<<pre2[l]-pre2[r]<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}
```



## C. Recover an RBS

### 标签

贪心, 构造

### 题意

![image-20220722101810946](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-22-021811.png)

### 思路

![image-20220722101830219](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-22-021830.png)

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
string s;

bool check(int _l,int _r){
    FOR(i,0,s.size()-1){
        if(s[i]=='?'){
            if(_l>=2){
                s[i]='(';
                _l--;
            }
            else if(_l==1){
                s[i]=')';
                _l=-1;
            }
            else if(_l==-1){
                s[i]='(';
                _l=-2;
                _r--;
            }
            else if(_r>=1){
                s[i]=')';
                _r--;
            }
        }
    }
    stack<char> stk;
    FOR(i,0,s.size()-1){
        if(s[i]=='(') stk.push(s[i]);
        if(s[i]==')'){
            if(!stk.empty()) stk.pop();
            else return false;
        }
        
    }
    return true;
}

void solve(){
    cin>>s;
    int l=0,r=0,len=s.size();
    for(auto i:s){
        if(i=='(') l++;
        if(i==')') r++;
    }
    int _l=len/2-l,_r=len/2-r;
    if(_l==0 or _r==0) {puts("YES");return;}
    if(check(_l,_r)) puts("NO");
    else puts("YES");
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

## D. Rorororobot

### 标签

贪心, 树状数组, 线段树

### 题意

![image-20220722110734233](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-22-030734.png)

### 思路

![image-20220722110748805](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-22-030748.png)

### 代码

(比 C 题容易想多了)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 2e5+7;
int a[N];

struct BIT{
    #define MAXN (int)2e5+7
    #define INF (int)1e9+7
    //const static int MAXN = 2e7+7;
    //const static int INF = 1e9+7;
    #define maxs(a,b) ((a)>(b)?(a):(b))
    #define mins(a,b) ((a)<(b)?(a):(b))
    struct node{
        int val,i;//数值,原始下标
        bool operator<(const node &x)const{
            return val<x.val;
        }
        bool operator>(const node &x)const{
            return val>x.val;
        }
    };
    int n;
    node v[MAXN],mi[MAXN],ma[MAXN];
    int lowbit(int x){
        return x&(-x);
    }
    void update(int x){
        v[x].i=x;
        while(x<=n){
            mi[x]=ma[x]=v[x];
            int lowx=lowbit(x);
            for(int i=1;i<lowx;i<<=1){
                mi[x]=mins(mi[x],mi[x-i]);
                ma[x]=maxs(ma[x],ma[x-i]);
            }
            x+=lowbit(x);
        }       
    }
    node qmin(int l,int r){//查最小值
        node ans=(node){INF,0};
        while(r>=l){
            ans=min(ans,v[r]);
            for(r=r-1;r-lowbit(r)>=l;r-=lowbit(r))
                ans=min(ans,mi[r]);
        }
        return ans;
    }
    node qmax(int l,int r){//查最大值
        node ans=(node){-INF,0};
        while(r>=l){
            ans=max(ans,v[r]);
            for(r=r-1;r-lowbit(r)>=l;r-=lowbit(r))
                ans=max(ans,ma[r]);
        }
        return ans;
    }
}tr;

void solve(){
    int n,m;
    cin>>n>>m;
    tr.n=m;
    FOR(i,1,m){
        cin>>tr.v[i].val;
        tr.update(i);
    }
    int q; cin>>q;
    while(q--){
        int sx,sy,fx,fy,k;
        cin>>sx>>sy>>fx>>fy>>k;
        if(sy>fy) {swap(sx,fx); swap(sy,fy);}
        if((sx-fx)%k!=0 or (sy-fy)%k!=0){
            cout<<"NO\n";continue;
        }
        int tp=((n-sx)/k)*k+sx;
        if(tp>tr.qmax(sy,fy).val) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; // cin>>T;
    while(T--) solve();
    return 0;
}
```

