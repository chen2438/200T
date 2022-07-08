#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int n;
int maze[107][107];
int dx[]={0, 1,1,1,2};
int dy[]={0,-1,0,1,0};

bool check_and_erase(int x, int y){
	FOR(i,0,4){
		int nx=x+dx[i], ny=y+dy[i];
		if(maze[nx][ny]==0) return false;
		else maze[nx][ny]=0;
	}
	return true;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	FOR(i,1,n){
		FOR(j,1,n){
			char c;cin>>c;
			if(c=='.') maze[i][j]=0;
			else maze[i][j]=1;
		}
	}
	FOR(i,1,n){
		FOR(j,1,n){
			if(maze[i][j]==1){
				if(!check_and_erase(i,j)) {cout<<"NO\n";exit(0);}
			}
		}
	}
	cout<<"YES\n";
	return 0;
}