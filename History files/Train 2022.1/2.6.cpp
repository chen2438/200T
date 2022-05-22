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

const int maxn=1000;
char a[maxn],b[maxn];
int dp[maxn][maxn];

int main(){
    int m,n;
    cin>>m>>(a+1)>>n>>(b+1);
    FOR(i,1,m)
        FOR(j,1,n){
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=maxs(dp[i][j-1],dp[i-1][j]);
        }
    cout<<dp[m][n]<<endl;
    return 0;
}
