#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

struct BIT{
    #define MAXN (int)5e5+7
    int n,c[MAXN];
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
}tr;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int m;
    cin>>tr.n>>m;
    int past=0,now;
    FOR(i,1,tr.n){
        cin>>now;
        tr.add(i,now-past);
        past=now;
    }
    int op,l,r,k;
    while(m--){
        cin>>op;
        if(op==1){
            cin>>l>>r>>k;
            tr.add(l,k);
            tr.add(r+1,-k);
        }
        else{
            cin>>l;
            cout<<tr.query(l)<<'\n';
        }
    }
    return 0;
}