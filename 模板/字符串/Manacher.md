# Manacher

**题目描述**

给出一个只由小写英文字符组成的字符串 $S$ ,求 $S$ 中最长回文串的长度 。

字符串长度为 $n$。

**输入格式**

一行小写英文字符组成的字符串 $S$。

**输出格式**

一个整数表示答案。

[P3805 【模板】manacher 算法](https://www.luogu.com.cn/problem/P3805)

[参考](https://12349.blog.luogu.org/manacher-zong-jie)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn=3e7;
char s[maxn],st[maxn];
int R[maxn];

int pre_process(){
    int len=strlen(st);
    int j=2;
    s[0]='^';
    s[1]='$';
    FOR(i,0,len-1){
        s[j++]=st[i];
        s[j++]='$';
    }
    s[j]='&';
    return j;
}

int manacher(){
    int len=pre_process();
    int mid=1,RB=1,ans=-1;
    FOR(i,1,len-1){
        if(i<RB) R[i]=min(RB-i,R[mid*2-i]);
        else R[i]=1;
        while(s[i-R[i]]==s[i+R[i]]) R[i]++;
        if(RB<i+R[i]){
            mid=i;
            RB=i+R[i];
        }
        ans=max(ans,R[i]-1);
    }
    return ans;
}

int main(){
    cin>>st;
    cout<<manacher();
    return 0;
}
```

### 输出回文串

![image-20220430152858207](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/2022-04-30-072858.png)

![image-20220430152908986](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/2022-04-30-072909.png)

```cpp
    FOR(i,1,ans+1){
        FOR(j,1,len-1){
            if(i<=R[j]){
                if(s[j-(R[i]-1)]=='$')continue;
                FOR(k,j-(i-1),j+(i-1)){
                    if(s[k]=='$')continue;
                    cout<<s[k];
                }cout<<endl;
            }
        }
    }
```





```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 6e5+7;

namespace MNCH{
    char s[N],st[N];
    int R[N],ans,len;
    unordered_map<string,int> ump;
    unordered_set<string> ust;
    int init(){
        int len=strlen(st);
        int j=2;
        s[0]='^';
        s[1]='$';
        FOR(i,0,len-1){
            s[j++]=st[i];
            s[j++]='$';
        }
        s[j]='&';
        return j;
    }
    int manacher(){
        len=init(),ans=-1;
        int mid=1,RB=1;
        FOR(i,1,len-1){
            if(i<RB) R[i]=min(RB-i,R[mid*2-i]);
            else R[i]=1;
            while(s[i-R[i]]==s[i+R[i]]) R[i]++;
            if(RB<i+R[i]){
                mid=i;
                RB=i+R[i];
            }
            ans=max(ans,R[i]-1);
        }
        return ans;
    }
    void save(){
        ust.clear();
        FOR(i,1,ans+1){
            FOR(j,1,len-1){
                if(i<=R[j]){
                    if(s[j-(R[i]-1)]=='$')continue;
                    string sav;
                    FOR(k,j-(i-1),j+(i-1)){
                        if(s[k]=='$')continue;
                        sav.push_back(s[k]);
                    }
                    // cout<<sav<<endl;
                    ust.insert(sav);
                }
            }
        }
        for(auto i:ust){
            // cout<<i<<endl;
            ump[i]++;
        }
    }
}

void solve(){
    int n; cin>>n;
    FOR(i,1,n){
        cin>>MNCH::st;
        MNCH::manacher();
        MNCH::save();
    }
    int ans=0;
    for(auto i:MNCH::ump){
        if(i.second==n) ans++;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}
```

