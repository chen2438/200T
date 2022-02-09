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
}e[101][101];//第GRP组的第i件物品

int save[101][101];//记忆数组
int len[101];//存储每组物品的个数（实际上就是m）
int n,m;//组数，每组的个数

int dfs(int GRP,int VOL){//第GRP组物品，剩余空间VOL
	if(save[GRP][VOL]!=0) return save[GRP][VOL];
	if(GRP>n) return 0;
	int res=dfs(GRP+1,VOL);

	for(int i=1;i<=len[GRP];i++){
		if(VOL<e[GRP][i].vol) continue;
		res=max(res,dfs(GRP+1,VOL-e[GRP][i].vol)+e[GRP][i].val);
	}
	return save[GRP][VOL]=res;
}
int main(){
	cin>>n>>m;
	int tmp;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>tmp;
			e[i][++len[i]]={j,tmp};
		}
	}
	cout<<dfs(1,m);
	return 0;
}