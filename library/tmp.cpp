#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define elif else if
using namespace std;

int a[500100],c[500100],n,m;

int lowbit(int x){
    return x&-x;
}

void add(int x,int v){
    while(x<=n)
        c[x]+=v,x+=lowbit(x);
}

int query(int x){
    int ans=0;
    while(x>=1)
        ans+=c[x],x-=lowbit(x);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cmd,x,y,k;
    cin>>n>>m;
    int past=0,now;
    FOR(i,1,n){
        cin>>now;
        add(i,now-past);
        past=now;
    } 
    while(m--){
        cin>>cmd;
        if(cmd==1){
            cin>>x>>y>>k;
            add(x,k);
            add(y+1,-k);
        }
        elif(cmd==2){
            cin>>x;
            cout<<query(x)<<'\n';
        }
    }
    return 0;
}