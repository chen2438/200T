#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
 
signed main(){
    int n, c;
    while(cin>>n>>c){
        int ans=0, pre=0, now;
        FOR(i,1,n){
            cin>>now;
            ans=max(ans,pre-now);
            pre=now;
        }
        ans-=c;
        if(ans>0) cout<<ans;
        else cout<<0;
    }
    return 0;
}