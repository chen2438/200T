#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int maxn=1e6+7;
int n,m,ans,cnt=1;
int dp[maxn],w[maxn],v[maxn];

int main(){
    int val,wet,ni;//价值，重量，有几个
    cin>>n>>m;//种类，最大载重
    FOR(i,1,n){
        scanf("%d%d%d",&val,&wet,&ni);
        for(int j=1;j<=ni;j<<=1){
            v[++cnt]=j*val,w[cnt]=j*wet;
            ni-=j;
        }
        if(ni) v[++cnt]=val*ni,w[cnt]=wet*ni;
    }
    
    FOR(i,1,cnt)
        ROF(j,m,w[i])
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    cout<<dp[m];
    return 0;
}