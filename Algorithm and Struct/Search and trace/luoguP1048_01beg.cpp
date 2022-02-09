//记忆化搜索
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

int vol[1007],val[1007],save[1007][1007];
int V,N;//V 背包容积，N 物品数量

int dfs(int OBJ,int VOL){//第obj个物品，背包剩余vol，dfs本身表示背包当前价值val
	if(VOL<0) return 0;
	if(OBJ>N) return 0;
	if(save[OBJ][VOL]!=0) return save[OBJ][VOL];
	int psb1,psb2=0;
	psb1=dfs(OBJ+1,VOL);
	if(VOL-vol[OBJ]>=0) psb2=dfs(OBJ+1,VOL-vol[OBJ])+val[OBJ];
	return save[OBJ][VOL]=max(psb1,psb2);
}

int main(){
	cin>>V>>N;
	FOR(i,1,N){
		cin>>vol[i]>>val[i];
	}
	int ANS=dfs(1,V);
	cout<<ANS<<endl;
	return 0;
}