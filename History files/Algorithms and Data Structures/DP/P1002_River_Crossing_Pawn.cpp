#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
using namespace std;

int dx[]={ 0,-2,-1, 1, 2, 2, 1,-1,-2};
int dy[]={ 0, 1, 2, 2, 1,-1,-2,-2,-1};

int bx,by,mx,my;
ll dp[40][40];
bool mark[40][40];

int main(){
    cin>>bx>>by>>mx>>my;
    bx+=2,by+=2,mx+=2,my+=2;
    mark[mx][my]=true;
    FOR(i,1,8)
        mark[mx+dx[i]][my+dy[i]]=true;
    dp[2][1]=1;
    FOR(i,2,bx){
        FOR(j,2,by){
            if(mark[i][j]) continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[bx][by];
    return 0;
} 