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
        int u=q.front();
        q.pop();
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