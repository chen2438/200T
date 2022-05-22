#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a));
using namespace std;

const int INF=(1<<28);
int vst[10][10];
int sx,sy,gx,gy,ans;
string bg,ed;
int dx[8]={ 1, 2,-1,-2, 1, 2,-1,-2};
int dy[8]={ 2, 1, 2, 1,-2,-1,-2,-1};

bool CheckEdge(int nx,int ny){
	if(nx>=0 and nx<8 and ny>=0 and ny<8 and vst[nx][ny]==0)
		return true;
	return false;
}

void init(){
	ans=INF;
	mem(vst);
	sx=bg[0]-'a',sy=bg[1]-'1';
	gx=ed[0]-'a',gy=ed[1]-'1';
}

void dfs(int x,int y,int step){
	if(step>=ans)return;
	if(x==gx and y==gy){
		ans=min(ans,step);
		return;
	}
	int nx,ny;
	FOR(i,0,7){
		nx=x+dx[i];
		ny=y+dy[i];
		if(CheckEdge(nx,ny)){
			vst[nx][ny]=1;
			dfs(nx,ny,step+1);
			vst[nx][ny]=0;
		}
	}
}

int main(){
	while(cin>>bg>>ed){
		init();
		vst[sx][sy]=1;
		dfs(sx,sy,0);
		printf("To get from %s to %s takes %d knight moves.\n",bg.c_str(),ed.c_str(),ans);
	}
	return 0;
}
