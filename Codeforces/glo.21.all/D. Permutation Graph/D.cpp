#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define MAXN (int)2.5e5+7
//#define debug

struct DATA{
    int v,i;//值,下标
    bool operator<(const DATA &x)const{
        return v<x.v;
    }
    bool operator>(const DATA &x)const{
        return v>x.v;
    }
};

struct NODE{
    DATA mi,ma;
};

int n;
DATA v[MAXN];
NODE pre[MAXN],suf[MAXN];

void ValInit(){//预处理前缀,后缀的最大最小值
    pre[1]={ v[1], v[1] };
    suf[n]={ v[n], v[n] };
    FOR(i,2,n){
        pre[i].mi=min(pre[i-1].mi,v[i]);
        pre[i].ma=max(pre[i-1].ma,v[i]);
    }
    ROF(i,n-1,1){
        suf[i].mi=min(suf[i+1].mi,v[i]);
        suf[i].ma=max(suf[i+1].ma,v[i]);
    }
}

int Dis(int l,int r,int k,int todo){//最短距离
    //k=-1找最小, k=1找最大; todo=-1找左边, todo=1找右边
	if(l==r) return 0;
	if(l+1==r) return 1;
	int mid;
    if(todo==-1){//左边一直找左边
        if(k==-1) mid=pre[r].mi.i;
        if(k==1) mid=pre[r].ma.i;
        return Dis(1,mid,-k,-1)+1;
    }
    if(todo==1){//右边一直找右边
        if(k==-1) mid=suf[l].mi.i;
        if(k==1) mid=suf[l].ma.i;
        return 1+Dis(mid,n,-k,1);
    }
    return 0;
}

int DisStart(){
	int mid=pre[n].ma.i;
	return Dis(1,mid,-1,-1)+Dis(mid,n,-1,1);
}

signed main(){
	int T=1;
    #ifndef debug
        cin>>T;
    #endif
	while(T--){
		cin>>n;
		FOR(i,1,n){
			scanf("%d",&v[i].v);
            v[i].i=i;
		}
        ValInit();
		cout<<DisStart()<<'\n';
	}
	return 0;
}