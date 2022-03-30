#include <iostream>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int MAXN = 1007;

int n, a[MAXN],dp[MAXN],from[MAXN];

void output(int x){
    if(!x) return;
    output(from[x]);
    cout<<a[x]<<" ";
}

int main(){
    n=1;
    while(cin>>a[n]) ++n;
    n--;
    FOR(i,1,n){
        dp[i]=1;
        from[i]=0;
        FOR(j,1,i-1){
            if(a[j]<a[i] and dp[i]<dp[j]+1)
                dp[i]=dp[j]+1,from[i]=j;
        }
    }
    
    int ans=dp[1],pos=1;
    FOR(i,1,n){
        if(ans<dp[i]) ans=dp[i],pos=i;
    }
    cout<<"max="<<ans<<endl;
    output(pos);
    return 0;
}
