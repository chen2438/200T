#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define Inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 3e5+5;
struct node{//结构体存每个区间 
	int l,r;
	long long val;
}nod[maxn];

bool cmp(node x,node y){//对结构体sort()所需函数 
	if(x.r==y.r) return x.l<y.l;
	else return x.r<y.r;//对各个区间按右端点升序排序,右端点相同按左端点升序排序 
}

/*--------------------------*/ 
/*-----以下为线段树部分-----*/ 
/*--------------------------*/ 

ll n,a[maxn<<2];//数组存储线段树,开4倍空间 
//x*2 等价于 x<<1 
//x*4 等价于 x<<2 
//x*2+1 等价于 x<<1|1 

void pushup(int root){//更新节点信息,这里是求左右子节点的最小值 
	a[root]=min(a[root<<1],a[root<<1|1]);
	//root*2是左下方节点,root*2+1是右下方节点 
}

void build(int root,int l,int r){//建树
	//root为当前节点在a[]的对应下标，即实际存储位置 
	//[l,r]表示当前节点区间 
	if(l==r){//到达叶子节点 
		a[root]=Inf;
		//初始化节点值为Inf,用于比最小值,同时参与判断是否所有 Steam 点数都被覆盖  
		return ;
	}
	int mid=l+r>>1;//左右递归,等价于min=(l+r)/2 
	build(root<<1  ,l    ,mid);
	build(root<<1|1,mid+1,r  );
	pushup(root);//递归完,更新本节点信息 
}
void update(int root,int l,int r,int pos,ll val){//点修改 
	//root,l,r含义同上
	//pos为线段树所表达的数组dp的实际下标 pos∈[1,298298+1] 
	//value是想要修改成的值 
	if(l==r){//到达叶子节点 
		a[root]=min(a[root],val);//修改为最小值 
		return ;
	}
	int mid=l+r>>1;
	//判断需要向左走还是向右走,从上往下一路走到叶子节点 
	if(pos<=mid) update(root<<1,l,mid,pos,val);
	else update(root<<1|1,mid+1,r,pos,val);
	//递归(走)完更新本节点信息 
	pushup(root);
}
ll query(int root,int l,int r,int ql,int qr){//区间查询 
	if(l>qr || r<ql) return Inf;
	//查询范围超出[ql,qr],且没有交叉部分.同时参与判断是否所有 Steam 点数都被覆盖  
	else if(l>=ql && r<=qr) return a[root];//在区间内直接返回值 
	else{//有交叉部分,递归到交叉部分,返回交叉部分的值 
		int mid=l+r>>1;
		return min(query(root<<1,l,mid,ql,qr),query(root<<1|1,mid+1,r,ql,qr));
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nod[i].l>>nod[i].r>>nod[i].val;
		nod[i].l++;nod[i].r++;
		//由于线段树习惯从1开始建立,而nod[i].l-1在l=1时等于0,所以把所有区间向右移1位 
	}
	sort(nod,nod+n,cmp);
	
	/*以下为线段树部分*/ 
	//线段树模拟数组dp[1 -> 298298+1] 
	build(1,1,maxn);//建树
	update(1,1,maxn,1,0);//线段树所模拟的dp[1]赋初值为0 
	/*---下面这个for循环,后文有可参考的等价代码---*/ 
	for(int i=0;i<n;i++){
		ll minn=query(1,1,maxn,nod[i].l-1,nod[i].r);//查询dp[l-1 -> r]最小值 
		minn+=nod[i].val;//最小值加上新值 
		update(1,1,maxn,nod[i].r,minn);
	}
	/*------------------------------------------*/
	ll ans=query(1,1,maxn,298298+1,298298+1);//查询线段树所模拟的数组dp[298298+1] 
	if(ans!=Inf) cout<<ans;
	else cout<<-1;
	return 0;
}
