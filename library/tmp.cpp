#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define maxn 100017  //元素总个数
#define elif else if
#define LL long long

struct SegmentTree{
    #define ls (rt<<1)//lson,左子树
    #define rs (rt<<1|1)
    LL Sum[maxn<<2],Add[maxn<<2];//Sum求和，Add为懒惰标记 
    LL A[maxn],n;//存原数组数据下标[1,n] 

    void PushUp(int rt){
        //更新节点信息 ，这里是求和
        Sum[rt]=Sum[ls]+Sum[rs];
    }

    void Build(int l,int r,int rt){
        //l,r:当前节点区间，rt:当前节点编号
        if(l==r) {//若到达叶节点 
            Sum[rt]=A[l];//储存数组值 
            return;
        }
        int m=(l+r)>>1;
        //左右递归 
        Build(l,m,ls);
        Build(m+1,r,rs);
        PushUp(rt);
    }

    void Update(int L,LL C,int l,int r,int rt){
        //l,r:当前节点区间,rt:当前节点编号
        if(l==r){//到叶节点，修改 
            Sum[rt]+=C;
            return;
        }
        int m=(l+r)>>1;
        //根据条件判断往左子树调用还是往右 
        if(L<=m) Update(L,C,l,m,ls);
        else Update(L,C,m+1,r,rs);
        PushUp(rt);//子节点更新了，所以本节点也需要更新信息 
    } 

    void PushDown(int rt,int ln,int rn){
        //ln,rn为左子树，右子树的数字数量。
        if(Add[rt]){
            //下推标记 
            Add[ls]+=Add[rt];
            Add[rs]+=Add[rt];
            //修改子节点的Sum使之与对应的Add相对应 
            Sum[ls]+=Add[rt]*ln;
            Sum[rs]+=Add[rt]*rn;
            //清除本节点标记 
            Add[rt]=0;
        }
    }

    void Update(int L,int R,LL C,int l,int r,int rt){
        //L,R:操作区间，l,r:当前节点区间，rt:当前节点编号 
        if(L<=l and r<=R){//如果本区间完全在操作区间[L,R]以内 
            Sum[rt]+=C*(r-l+1);//更新数字和，向上保持正确
            Add[rt]+=C;//增加Add标记，表示本区间的Sum正确，子区间的Sum仍需要根据Add的值来调整
            return ; 
        }
        int mid=(l+r)>>1;
        PushDown(rt,mid-l+1,r-mid);//下推标记
        //这里判断左右子树跟[L,R]有无交集，有交集才递归 
        if(L<=mid) Update(L,R,C,l,mid,ls);
        if(R>mid) Update(L,R,C,mid+1,r,rs); 
        PushUp(rt);//更新本节点信息 
    } 

    LL Query(int L,int R,int l,int r,int rt){
        //L,R:操作区间,l,r:当前节点区间，rt:当前节点编号
        if(L<=l and r<=R){
            //在区间内，直接返回 
            return Sum[rt];
        }
        int mid=(l+r)>>1;
        //下推标记，否则Sum可能不正确
        PushDown(rt,mid-l+1,r-mid); 
        
        //累计答案
        LL ANS=0;
        if(L<=mid) ANS+=Query(L,R,l,mid,ls);
        if(R>mid) ANS+=Query(L,R,mid+1,r,rs);
        return ANS;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    SegmentTree st;
    int n,m;
    cin>>n>>m;
    FOR(i,1,n)
        cin>>st.A[i];
    st.Build(1,n,1);
    int o,x,y,k;
    FOR(i,1,m){
        cin>>o;
        if(o==1){
            cin>>x>>y>>k;
            st.Update(x,y,k,1,n,1);
        }
        elif(o==2){
            cin>>x>>y;
            cout<<st.Query(x,y,1,n,1)<<endl;
        }
    }
    return 0;
} 