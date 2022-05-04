#include<bits/stdc++.h>
#define mem(a) memset(a,0,sizeof(a))
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
const int INF=(1<<28);
using namespace std;

int n,m,ans=0;
int matx[1007][1007];
int sx,sy;

int dx[8]={1,0,-1,0};//方向向量
int dy[8]={0,1,0,-1};

struct node{
	int x,y;
};
queue<node> r;

/*void init(){//初始化与重置
	FOR(i,0,8)
		FOR(j,0,8)
			d[i][j]=INF;
	sx=bg[0]-'a',sy=bg[1]-'1';
	ex=ed[0]-'a',ey=ed[1]-'1';
}*/

bool CheckEdge(int nx,int ny){//检查边界条件
	if(nx>=1 and nx<=n and ny>=1 and ny<=m)
		return true;
	return false;
}

void bfs(){//BFS
	matx[sx][sy]=0;ans=1;
	r.push({sx,sy});//起点入队
	while(!r.empty()){
		node t=r.front();//查询队首
		r.pop();//弹出队首
		int nx,ny;
		FOR(i,0,3){
			nx=t.x+dx[i];
			ny=t.y+dy[i];
			if(matx[nx][ny] and CheckEdge(nx,ny)){
				//d[nx][ny]=d[t.x][t.y]+1;
				matx[nx][ny]=0;
				ans++;
				r.push({nx,ny});//添加到队尾
			}
		}
	}
}

int main(){
    cin>>n>>m;
    FOR(i,1,n){
    	FOR(j,1,m){
    		char o;cin>>o;
    		if(o=='N')matx[i][j]=0;
    		else matx[i][j]=1;
    	}
    }
    cin>>sx>>sy;
    if(matx[sx][sy]==0){
    	cout<<"0\n";
    	return 0;
    }
    //cout<<"debug\n";
	bfs();
	cout<<ans<<endl;
	
	return 0;
}

