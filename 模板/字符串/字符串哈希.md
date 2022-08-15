### [P3370 【模板】字符串哈希](https://www.luogu.com.cn/problem/P3370)

![image-20220420163733869](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/2022-04-20-083734.png)

[参考](https://fanfansann.blog.csdn.net/article/details/107555631)

#### 单哈希

```cpp
#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int p=131;//13331
const int N=1e7+7;
int n,m;
ll a[N];
char str[N];

ll get_hash(char s[]){
    ll res=0;
    int len=strlen(s);
    FOR(i,0,len-1)
        res=res*p+(ll)s[i];
    return res;
}

int main(){
    cin>>n;
    FOR(i,1,n){
        cin>>str;
        a[i]=get_hash(str);
    }
    int ans=1;
    sort(a+1,a+1+n);
    FOR(i,1,n-1)
        if(a[i]!=a[i+1]) ans++;
    cout<<ans;
    return 0;
}
```

#### 双哈希

```cpp
// #pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define endl '\n'
using namespace std;

const int N = 1e5+10;
const int mod[]={19260817,19660813},base=131;

struct node{
    int x,y;
    bool operator<(const node &y)const{
        return x<y.x;
    }
}ha[N];

char s[N];

int Hash(char s[],int idx){
    int len=strlen(s);
    int res=0;
    FOR(i,0,len-1)
        res=(res*base+(int)s[i])%mod[idx];
    return res;
}

node get_hash(char s[]){
    return {Hash(s,0),Hash(s,1)};
}

int cnt_hash(int n){
    sort(ha+1,ha+n+1);
    int res=1;
    FOR(i,2,n)
        if(ha[i-1].x!=ha[i].x or ha[i-1].y!=ha[i].y) res++;
    return res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    FOR(i,1,n){
        cin>>s;
        ha[i]=get_hash(s);
    }
    int ans=cnt_hash(n);
    cout<<ans<<endl;
    return 0;
}
```



### AcWing 4269. 校庆

https://www.acwing.com/problem/content/description/4272/

![image-20220702150418139](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207021504205.png)

![image-20220702150428048](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207021504102.png)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin>>n;
    string id;
    unordered_set<string> hash;
    while (n -- ){
        cin>>id;
        hash.insert(id);
    }
    cin>>m;
    string a, b;
    int cnt = 0;
    while (m -- ){
        cin>>id;
        if (hash.count(id)){
            cnt ++ ;
            if (a.empty() || a.substr(6, 8) > id.substr(6, 8)) a = id;
        }
        if (b.empty() || b.substr(6, 8) > id.substr(6, 8)) b = id;
    }
    cout<<cnt<<endl;
    if (cnt) cout<<a<<endl;
    else cout<<b<<endl;
    return 0;
}
```

### AcWing 139. 回文子串的最大长度

#### 题目描述

![image-20220815164233440](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-08-15-084233.png)

#### 代码

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define endl '\n'
using namespace std;

typedef unsigned long long ULL;
const int N = 2000010, base = 131;

char str[N];
ULL hl[N], hr[N], p[N];

ULL get(ULL h[], int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(){
    int T = 1;
    while (scanf("%s", str + 1), strcmp(str + 1, "END")){
        int n = strlen(str + 1);
        for (int i = n * 2; i; i -= 2){
            str[i] = str[i / 2];
            str[i - 1] = 'a' + 26;
        }
        n *= 2;
        p[0] = 1;
        for (int i = 1, j = n; i <= n; i ++, j -- ){
            hl[i] = hl[i - 1] * base + str[i] - 'a' + 1; 
            hr[i] = hr[i - 1] * base + str[j] - 'a' + 1;
            p[i] = p[i - 1] * base;
        }
        int res = 0;
        FOR(i,1,n){
            int l = 0, r = min(i - 1, n - i);
            while (l < r){
                int mid = l + r + 1 >> 1;
                if(get(hl,i-mid,i-1)!=get(hr,n-(i+mid)+1,n-(i+1)+1))
                    r=mid-1;
                else l = mid;
            }
            if (str[i - l] <= 'z') res = max(res, l + 1);
            else res = max(res, l);
        }
        printf("Case %d: %d\n", T ++ , res);
    }
    return 0;
}
```

