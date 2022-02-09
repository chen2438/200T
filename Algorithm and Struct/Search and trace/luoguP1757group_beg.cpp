/*此方法是错误的，原因未知
//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(register int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(register int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

struct node{//体积，价值，组数
	int vol,val,group;
}e[1010];

int vst[110],save[1010][1010];
int m,n;//背包容积，物品数量

int dfs(int OBJ,int VOL){//第OBJ件物品，剩余空间VOL
	if(save[OBJ][VOL]>0) return save[OBJ][VOL];
	if(OBJ==n+1) return 0;
	
	int psb1,psb2=0;
	psb1=dfs(OBJ+1,VOL);

	if(vst[e[OBJ].group]!=0) return save[OBJ][VOL]=psb1;

	if(VOL>=e[OBJ].vol){
		vst[e[OBJ].group]=1;
		psb2=dfs(OBJ+1,VOL-e[OBJ].vol)+e[OBJ].val;
		vst[e[OBJ].group]=0;
	}
	return save[OBJ][VOL]=max(psb1,psb2);
}
int main(){
	cin>>m>>n;
	FOR(i,1,n)
		cin>>e[i].vol>>e[i].val>>e[i].group;
	cout<<dfs(1,m);
	return 0;
}
*/
//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

struct node{
	int vol,val;//体积，价值
}e[1001][1001];//第GRP组的第i件物品

int save[1001][1001];//记忆数组
int len[1001];//存储每组物品的个数（实际上就是m）
int n,m;//物品数量，背包容积
const int maxGRP=100;

int dfs(int GRP,int VOL){//第GRP组物品，剩余空间VOL
	if(save[GRP][VOL]!=0) return save[GRP][VOL];
	if(GRP>maxGRP) return 0;
	int res=dfs(GRP+1,VOL);

	for(int i=1;i<=len[GRP];i++){
		if(VOL<e[GRP][i].vol) continue;
		res=max(res,dfs(GRP+1,VOL-e[GRP][i].vol)+e[GRP][i].val);
	}
	return save[GRP][VOL]=res;
}
int main(){
	cin>>m>>n;
	int vol,val,grp;
	FOR(i,1,n){
		cin>>vol>>val>>grp;
		e[grp][++len[grp]]={vol,val};
	}
	cout<<dfs(1,m);
	return 0;
}