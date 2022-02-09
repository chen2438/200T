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

int dp[207][207],v[207];
int main(){
    int n,ans=0;
    cin>>n;
    FOR(i,1,n){
        cin>>v[i];
        v[i+n]=v[i];//环形，复制一倍到尾部
    }
    FOR(i,1,2*n)//遍历终点
        ROF(j,i-1,1)//从后向前推终点之前的起点
            FOR(k,j,i-1)//分界点
            //ROF(k,i-1,j) 正序或倒序都可以
                dp[j][i]=max(dp[j][i],v[j]*v[k+1]*v[i+1]+dp[j][k]+dp[k+1][i]);
                //为什么3个相乘的数组下标(j,k+1,i+1)不相邻呢，
                //因为他们之间的已经被合并掉了，
                //左边是j->k，右边是k+1->i，这是合并后的能量。
    FOR(i,1,n)
        ans=max(ans,dp[i][i+n-1]);//求各个区间的最大值
    cout<<ans<<endl;
    return 0;
}