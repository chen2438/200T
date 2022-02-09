#pragma GCC optimize(2)
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

int matx[10][10];
int ans;

bool check_edge(int x,int y){
	if(x>=1 and x<=8 and y>=1 and y<=8)
		return true;
	return false;
}

bool check_unblocked(int x,int y){
	FOR(i,1,8){
		if(matx[i][y]==1)return false;
		if(matx[x][i]==1)return false;
	}
	int tx=x,ty=y;
	while(check_edge(tx,ty)) if(matx[tx++][ty++]==1)return false;
	tx=x,ty=y;
	while(check_edge(tx,ty)) if(matx[tx--][ty++]==1)return false;
	tx=x,ty=y;
	while(check_edge(tx,ty)) if(matx[tx++][ty--]==1)return false;
	tx=x,ty=y;
	while(check_edge(tx,ty)) if(matx[tx--][ty--]==1)return false;
	return true;
}

void dfs(int x,int y,int queen){
	if(x>queen)return;
	if(queen==8){
		ans++;
		return;
	}
	FOR(nx,x+1,8)
		FOR(ny,1,8){
			if(matx[nx][ny]==0 and check_unblocked(nx,ny)){
				matx[nx][ny]=1;
				dfs(nx,ny,queen+1);
				matx[nx][ny]=0;
			}
		}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		mem(matx);
		ans=0;
		cin>>n;
		matx[1][n]=1;
		dfs(1,n,1);
		cout<<ans<<endl;
	}
	return 0;
}