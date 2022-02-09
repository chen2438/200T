#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(register int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(register int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

int dp[3000],presum[3000];

int main(){
    int n,m;
    cin>>n>>m;
    int x;
    FOR(i,1,n){
        cin>>x;
        presum[i]=presum[i-1]+x;
    }
    FOR(i,1,n){
        int min0=INF;
        FOR(j,1,i)
            min0=min(min0,dp[i-j]+presum[j]+2*m);
        dp[i]=min0;
    }
    cout<<dp[n]-m<<endl;
    return 0;
}
