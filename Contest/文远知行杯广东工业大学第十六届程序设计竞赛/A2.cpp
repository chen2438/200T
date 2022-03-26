#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
 
const int MAXN=5e7+7;
int a[MAXN],h[MAXN];
int n,m;
 
int lowbit(int x){
    return x&(-x);
}

void updata(int x){
    int lx,i;
    while(x<=n){
        h[x]=a[x];
        lx=lowbit(x);
        for(i=1;i<lx;i<<=1)
            h[x]=max(h[x],h[x-i]);
        x+=lowbit(x);
    }       
}

int query(int x,int y){
    int ans=0;
    while(y>=x){
        ans=max(a[y],ans);
        --y;
        for(;y-lowbit(y)>=x;y-=lowbit(y))
            ans=max(h[y],ans);
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x,y,ans;
    cin>>n>>m;
    FOR(i,1,n){
        a[i]=n%i;
        updata(i);
    }
    FOR(i,1,m){
        cin>>x>>y;
        ans=query(x,y);
        cout<<ans<<'\n';
    }
    return 0;
}