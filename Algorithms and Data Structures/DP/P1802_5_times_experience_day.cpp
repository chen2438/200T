#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

int win[1100],lose[1100],use[1100],dp[1100];

int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,1,n)
    	cin>>lose[i]>>win[i]>>use[i];
    FOR(i,1,n){
        ROF(j,m,0){
         	if(j>=use[i]) dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
          	else dp[j]+=lose[i];
        }
    }
    cout<<5ll*dp[m];
    return 0;
}