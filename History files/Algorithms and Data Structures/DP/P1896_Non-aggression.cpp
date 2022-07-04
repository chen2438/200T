#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

long long sta[2005],sit[2005],f[15][2005][105];
int n,k,cnt=0;

void dfs(int x,int num,int cur){
    if(cur>=n){//当前状态处理完毕（国王位置越界了）
        sit[++cnt]=x;//新建一个状态
        sta[cnt]=num;
        return;
    }
    dfs(x,num,cur+1);//cur位置不放国王
    dfs(x+(1<<cur),num+1,cur+2);//cur位置放国王，与它相邻的位置不能再放国王
}

bool compatible(int j,int x){
    if(sit[j] & sit[x]) return false;
    if((sit[j]<<1) & sit[x]) return false;
    if(sit[j] & (sit[x]<<1)) return false;
    return true;
}

int main(){
    cin>>n>>k;
    dfs(0,0,0);//先预处理一行的所有合法状态
    FOR(j,1,cnt)
        f[1][j][sta[j]] = 1;
    FOR(i,2,n)
        FOR(j,1,cnt)
            FOR(x,1,cnt){
                if(!compatible(j,x)) continue;//排除不合法转移
                FOR(l,sta[j],k)
                    f[i][j][l]+=f[i-1][x][l-sta[j]];
            }
    long long ans=0;
    FOR(i,1,cnt)
        ans+=f[n][i][k];//累加答案
    cout<<ans;
    return 0;
}