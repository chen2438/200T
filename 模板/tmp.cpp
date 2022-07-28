#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int N = 1e6+7, S = 1, M = 1e6+7;

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
    freopen("/Users/nanmener/Documents/GitHub/200T/模板/P3808_1.in","r",stdin);
    int T=1; //cin>>T;
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
        //1000000
        for (int i = 0, j = 0; i<str.size(); i ++ ){//kmp匹配
            int t = str[i] - 'a';
            j = tr[j][t];
            int p = j;
            // printf("i=%d\n",i);
            while (p and cnt[p]){
                printf("p=%d \n",p);
                res += cnt[p];
                cnt[p] = 0;
                p = ne[p];
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}