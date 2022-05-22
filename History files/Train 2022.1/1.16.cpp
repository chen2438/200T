#include<bits/stdc++.h>
#define mem(a) memset(a,0,sizeof(a))
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int INF=(1<<28),MAX_N=501,MAX_M=501;

struct node{
	int nx,ny;
};

char maze[MAX_N][MAX_M];
int N,M,sx,sy,gx,gy;
int d[MAX_N][MAX_M];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int check(int nx,int ny){
	if(0<=nx and nx<N and 0<=ny and ny<M and d[nx][ny]==INF){
		if(maze[nx][ny]=='.') return 1;
	}
	return 0;
}

int bfs(){
	FOR(i,0,N-1)
		FOR(j,0,M-1)
			d[i][j]=INF;
	queue<node> que;
	que.push((node){sx,sy});
	d[sx][sy]=0;
	while(que.size()){
		node p=que.front();
		que.pop();
		if(p.nx==gx and p.ny==gy) break;
		FOR(i,0,3){
			int nx=p.nx+dx[i],ny=p.ny+dy[i];
			if(check(nx,ny)==1){
				que.push((node){nx,ny});
				d[nx][ny]=d[p.nx][p.ny]+1;
			}
		}
	}
	return d[gx][gy];
}

int main(){
	int T;cin>>T;
	while(T--){
		mem(maze);
		mem(d);
		int c;
		cin>>N>>M>>c;
		FOR(i,0,N-1)
			FOR(j,0,M-1){
				cin>>maze[i][j];
				if(maze[i][j]=='S'){
					sx=i,sy=j;
					maze[i][j]='.';	
				}
				if(maze[i][j]=='E'){
					gx=i,gy=j;
					maze[i][j]='.';
				}
			}
		int res=bfs();
		if(res==INF)cout<<-1;
		else cout<<res;
	} 
	return 0;
} 

