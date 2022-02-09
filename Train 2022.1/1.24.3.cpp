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
}e[101000];

int save[1010][1100];
int M,N,m,n;//背包容积，物品数量

int dfs(int OBJ,int VOL){//第OBJ件物品，剩余空间VOL
	if(save[OBJ][VOL]!=0) return save[OBJ][VOL];
	if(OBJ>n) return 0;
	int res=dfs(OBJ+1,VOL);

	FOR(i,1,M){
		if(VOL<e[(OBJ-1)*M+i].vol) continue;
		res=max(res,dfs(OBJ+1,VOL-e[(OBJ-1)*M+i].vol)+e[(OBJ-1)*M+i].val);
	}
	return save[OBJ][VOL]=res;
}
int main(){
	cin>>n>>m;
	M=m,N=m*n;
	int cnt=1;
	FOR(i,1,n){
		FOR(j,1,m){
			e[cnt].vol=j;
			cin>>e[cnt].val;
			e[cnt].group=i;
			cnt++;
		}
	}
	cout<<dfs(1,m);
	return 0;
}