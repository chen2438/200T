//#pragma GCC optimize(2)
//clock_t st=clock();
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

int dp1[207][207],dp2[207][207];
int v[207],presum[207];

int sum(int x,int y){//计算区间[x,y]的和
    return presum[y]-presum[x-1];
}

int main(){
    int n;
    cin>>n;
    FOR(i,1,n){
        cin>>v[i];
        v[i+n]=v[i];//环形，复制一倍到尾部
    }
    FOR(i,1,2*n)
        presum[i]=presum[i-1]+v[i];//计算前缀和，方便区间求和

    FOR(i,1,2*n)//遍历终点
        ROF(j,i-1,1){//从后向前推终点之前的起点
            dp1[j][i]=INF,dp2[j][i]=inf;
            FOR(k,j,i-1){//分界点
                dp1[j][i]=min(dp1[j][i],dp1[j][k]+dp1[k+1][i]+sum(j,i));
                dp2[j][i]=max(dp2[j][i],dp2[j][k]+dp2[k+1][i]+sum(j,i));
            }
        }

    int min0=INF,max0=inf;
    FOR(i,1,n){
        min0=min(min0,dp1[i][i+n-1]);//求各个区间的最大值
        max0=max(max0,dp2[i][i+n-1]);
    }
    cout<<min0<<'\n'<<max0;
    return 0;
}