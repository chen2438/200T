#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define int long long
const int N = 1e5+7;
int a[N],b1[N],b2[N],c[N];
int pre[N],suf[N];

void solve(){
    memset(b1,0,sizeof b1);
    memset(b2,0,sizeof b2);
    memset(pre,0,sizeof pre);
    memset(suf,0,sizeof suf);
    int n; cin>>n;
    FOR(i,1,n){
        cin>>a[i];
    }
    if(n%2==1){
        int ans=0;
        for(int i=2;i<=n-1;i+=2){
            if(a[i-1]>=a[i]){
                ans += a[i-1]+1-a[i];
                a[i]=a[i-1]+1;
            }
            if(a[i]<=a[i+1]){
                ans += a[i+1]+1-a[i];
                a[i]=a[i+1]+1;
            }
        }
        cout<<ans<<endl;
        return;
    }
    
    FOR(i,1,n) c[i]=a[i];
    for(int i=2;i<=n-1;i+=2){
        if(c[i-1]>=c[i]){
            b1[i] += c[i-1]+1-c[i];
            c[i]=c[i-1]+1;
        }
        if(c[i]<=c[i+1]){
            b1[i] += c[i+1]+1-c[i];
            c[i]=c[i+1]+1;
        }
    }
    FOR(i,1,n) pre[i]=b1[i]+pre[i-1];
    
    FOR(i,1,n) c[i]=a[i];
    for(int i=3;i<=n-1;i+=2){
        if(c[i-1]>=c[i]){
            b2[i] += c[i-1]+1-c[i];
            c[i]=c[i-1]+1;
        }
        if(c[i]<=c[i+1]){
            b2[i] += c[i+1]+1-c[i];
            c[i]=c[i+1]+1;
        }
    }
    ROF(i,n,1) suf[i]=b2[i]+suf[i+1];
    
    
    // FOR(i,1,n) cout<<b1[i]<<" ";
    //  cout<<endl;
    //  FOR(i,1,n) cout<<b2[i]<<" ";
    //  cout<<endl;
    
    //  FOR(i,1,n) cout<<pre[i]<<" ";
    //  cout<<endl;
    //  FOR(i,1,n) cout<<suf[i]<<" ";
    //  cout<<endl;
     
    int pos,min0=1e9;
    FOR(i,0,n-1){
        if(min0>pre[i]+suf[i+1]){
            min0=pre[i]+suf[i+1];
            pos=i;
        }
    }
    cout<<min0<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}