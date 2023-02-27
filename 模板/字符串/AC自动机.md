AC 自动机 = trie 上 kmp => trie 图

复杂度: $O(n)$

AC 自动机: 对 trie 建立一个 next 数组

KMP: 对一个单链 trie (一维数组) 建立一个 next 数组

![image-20220728151823557](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-28-071823.png)

![image-20220728152306010](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-28-072306.png)

### [P3808 【模板】AC 自动机（简单版）](https://www.luogu.com.cn/problem/P3808)

#### 题目描述

![image-20230227224323811](https://media.opennet.top/i/2023/02/27/63fcc18d98f6f.png)

![image-20230227224339344](https://media.opennet.top/i/2023/02/27/63fcc19c762ba.png)

![image-20230227224351795](https://media.opennet.top/i/2023/02/27/63fcc1a91006e.png)

#### 代码

[参考](https://oi-wiki.org/string/ac-automaton/#_8)

```cpp
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int N=1e6+7;
int n;

namespace AC {
int tr[N][26],tot;
int e[N],fail[N];

void insert(char *s) {
    int u=0;
    for(int i=1;s[i];i++){
        if(!tr[u][s[i]-'a']) tr[u][s[i]-'a']=++tot;//如果没有则插入新节点
        u=tr[u][s[i]-'a'];//搜索下一个节点
    }
    e[u]++;//尾为节点 u 的串的个数
}

queue<int> q;

void build() {
    FOR(i,0,25)
        if(tr[0][i]) q.push(tr[0][i]);
    while(q.size()){
        int u=q.front(); q.pop();
        FOR(i,0,25){
            if(tr[u][i]){
                fail[tr[u][i]]=tr[fail[u]][i];//fail数组：同一字符可以匹配的其他位置
                q.push(tr[u][i]);
            }
            else tr[u][i]=tr[fail[u]][i];
        }
    }
}

int query(char *t){
    int u=0,res=0;
    for(int i=1;t[i];i++){
        u=tr[u][t[i]-'a'];//转移
        for(int j=u;j and e[j]!=-1;j=fail[j]){
            res+=e[j],e[j]=-1;
        }
    }
    return res;
  }
}//namespace AC

char s[N];

int main(){
    cin>>n;
    FOR(i,1,n)
        cin>>(s+1),AC::insert(s);
    cin>>(s+1);
    AC::build();
    cout<<AC::query(s);
    return 0;
}
```

### AcWing 1282. 搜索关键词

https://www.acwing.com/problem/content/description/1284/

#### 题目描述

![image-20230227224447600](https://media.opennet.top/i/2023/02/27/63fcc1e0d57e5.png)

#### 代码

```cpp
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int N = 1e4+7, S = 51, M = 1e6+7;

int n;
int tr[N * S][26], cnt[N * S], idx;
int ne[N * S];

void insert(string str){
    int p = 0;
    FOR(i,0,str.size()-1){
        int t = str[i] - 'a';
        if (!tr[p][t]) tr[p][t] = ++ idx;
        p = tr[p][t];
    }
    cnt[p] ++ ;
}

void build(){
    queue<int> q;
    FOR(i,0,25)
        if (tr[0][i]) q.push(tr[0][i]);
    while (!q.empty()){
        int t = q.front(); q.pop();
        FOR(i,0,25){
            int p = tr[t][i];
            if (!p) tr[t][i] = tr[ne[t]][i];// 路经压缩
            else{
                ne[p] = tr[ne[t]][i];
                q.push(p);
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while (T -- ){
        mem(tr),mem(cnt),mem(ne);
        idx = 0;
        string str;
        cin>>n;
        FOR(i,0,n-1){
            cin>>str;
            insert(str);
        }
        build();
        cin>>str;
        int res = 0;
        for (int i = 0, j = 0; i<str.size(); i ++ ){//kmp匹配
            int t = str[i] - 'a';
            j = tr[j][t];
            int p = j;
            while (p and cnt[p]!=-1){
                res += cnt[p];
                cnt[p] = -1;
                p = ne[p];
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
```

