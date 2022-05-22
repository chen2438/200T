#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long

const int maxn=2e6+7;
ll rm[maxn];
ll dat[100]={0,1};
ll ans[maxn];
int n,m,q;

inline int rd(){
    char ch=getchar();
    int s=0,w=1;
    while(ch<'0' || ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        s=s*10+ch-'0',
        ch=getchar();
    }
    return s*w;
}

void change(int l,int r,int x){
    FOR(i,l,r){
        rm[i]=rm[i]^dat[x];
    }
}

bool query(int l,int r,int x){
    FOR(i,l,r){
        if(rm[i]&dat[x])return true;
    }
    return false;
}

signed main(){
    //cin.tie(0)->sync_with_stdio(0);
    FOR(i,2,60){
        dat[i]=dat[i-1]*2;
    }

    n=rd(),m=rd(),q=rd();
    int o,l,r,x;
    FOR(i,1,q){
        //scanf("%d%d%d%d",&o,&l,&r,&x);
        o=rd(),l=rd(),r=rd(),x=rd();
        if(o==1){
            change(l,r,x);
        }
        if(o==2){
            if(query(l,r,x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}