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

const int maxn=1007;
int n,a[maxn][maxn],dp[maxn][maxn],ans; 

int main(){
    cin>>n;
    FOR(i,1,n)
        FOR(j,1,i)
            cin>>a[i][j];

    FOR(i,1,n)
        FOR(j,1,i)
            dp[i][j]=maxs(dp[i-1][j-1],dp[i-1][j])+a[i][j];

    FOR(i,1,n)
        ans=maxs(ans,dp[n][i]);

    cout<<ans<<endl;
    return 0; 
} 