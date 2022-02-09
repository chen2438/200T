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
int n,ans;

bool check_edge(int x,int y){
	if(x>=1 and x<=n and y>=1 and y<=n)
		return true;
	return false;
}

bool check_unblocked(int x,int y){
	FOR(i,1,n){
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

void print(){
	FOR(i,1,n)
		FOR(j,1,n)
			if(matx[i][j]==1) printf("%5d",j);
	putchar('\n');
}

void dfs(int x,int y,int queen){
	if(x>queen)return;
	if(queen==n){
		print();
		ans++;
		return;
	}
	FOR(nx,x+1,n)
		FOR(ny,1,n){
			if(matx[nx][ny]==0 and check_unblocked(nx,ny)){
				matx[nx][ny]=1;
				dfs(nx,ny,queen+1);
				matx[nx][ny]=0;
			}
		}
}

int main(){
	ans=0;
	cin>>n;
	FOR(i,1,n){
		mem(matx);
		matx[1][i]=1;
		dfs(1,i,1);
	}
	if(ans==0)cout<<"no solute!\n";
	return 0;
}