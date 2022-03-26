#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn=5e5+7; 

int a[maxn]; 
struct node{
    int l,r;
    int ma,cnt;
}t[maxn];

int ans1,n,m;

void push_up(int p){
    t[p].ma=max(t[2*p].ma,t[2*p+1].ma);
    if(t[2*p].ma==t[2*p+1].ma) t[p].cnt=t[2*p].cnt+t[2*p+1].cnt;
    else if(t[2*p].ma>t[2*p+1].ma) t[p].cnt=t[2*p].cnt;
    else t[p].cnt=t[2*p+1].cnt;
}

void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;t[p].cnt=0;
    if(l==r){t[p].ma=a[l];t[p].cnt=1;return;}
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    push_up(p);
}

void update(int p,int x,int k){
    if(t[p].l==t[p].r){t[p].ma=k;t[p].cnt=1;return;} 
    int mid=(t[p].l+t[p].r)/2;
    if(x<=mid) update(2*p,x,k);
    else update(2*p+1,x,k);
    push_up(p);
} 

void query(int p,int l,int r){
    int L=t[p].l,R=t[p].r;
    if(L>=l and R<=r){ans1=max(ans1,t[p].ma);return;}
    int mid=(L+R)/2;
    if(l<=mid) query(2*p,l,r); 
    if(r>mid) query(2*p+1,l,r);
    push_up(p);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    FOR(i,1,n){
        a[i]=n%i;
    }
    build(1,1,n);
    int x,y;
    FOR(i,1,m){
        cin>>x>>y;
        ans1=0;
        query(1,x,y);
        cout<<ans1<<'\n';
    }
    return 0;
}