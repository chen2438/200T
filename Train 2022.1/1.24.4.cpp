
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

struct node{//体积，价值，组数
	int vol,val,group;
}e[1010];

int vst[110],save[1010][1010];
int m,n;//

int dfs(int OBJ,int VOL){//第OBJ件物品，剩余空间VOL
	if(save[OBJ][VOL]>0) return save[OBJ][VOL];
	if(OBJ==n*m+1) return 0;
	if(vst[e[OBJ].group]!=0) return save[OBJ][VOL]=dfs(OBJ+1,VOL);
	int psb1,psb2=0;
	
	if(VOL>=e[OBJ].vol){
		vst[e[OBJ].group]=1;
		psb2=dfs(OBJ+1,VOL-e[OBJ].vol)+e[OBJ].val;
	}
	psb1=dfs(OBJ+1,VOL);
	if(psb1>=psb2 and VOL>=e[OBJ].vol) vst[e[OBJ].group]=0;
	return save[OBJ][VOL]=max(psb1,psb2);
}
int main(){
	cin>>n>>m;
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