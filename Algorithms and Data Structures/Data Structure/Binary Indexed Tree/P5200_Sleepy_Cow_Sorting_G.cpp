#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int MAXN=5e5+7;
int n;
int tree[MAXN],a[MAXN];

inline int lowbit(int x){
    return x&-x;
}

void update(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}

int sum(int x){
    int res=0;
    while(x>0){
        res+=tree[x];
        x-=lowbit(x);
    }
    return res;
}

int main(){
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    int k=n-1;
    while(k>0 and a[k]<a[k+1])
        k--;
    cout<<k<<endl;
    FOR(i,k+1,n)//上升后缀在树状数组标记为1
        update(a[i],1);
    FOR(i,1,k){//处理前面的非上升序列
        cout<<k-i+sum(a[i])<<" ";//(k-i)是当前位置到上升序列第一个数的距离
        //sum(a[i])是a[i]在上升序列中的位置到上升序列第一个数的距离
        update(a[i],1);
    }
    return 0;
}