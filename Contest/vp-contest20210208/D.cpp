//#pragma GCC optimize(2)
//clock_t st=clock();
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

int n,m;
int a[25][25];
int ed,vst[25],index;

void dfs(int step,long long num){
	if(step==ed){
		a[ed][index++]=num;
		return;
	}
	FOR(i,1,n){
		if(vst[i]==0 and num*a[ed-1][i]<=m){
			vst[i]=1;
			dfs(step+1,num*a[ed-1][i]);
			vst[i]=0;
		}
	}
}

int main(){
	cin>>n>>m;
	FOR(i,1,n){
		cin>>a[1][i];
	}
	sort(a[1]+1,a[1]+n+1);
	//FOR(i,2,n){
	int i=2;
		mem(vst);
	//	vst[1]=1;
		ed=i;
		index=1;
		dfs(0,1);
	//}
	FOR(i,1,n){
		cout<<a[2][i]<<" ";
	}

	return 0;
}
