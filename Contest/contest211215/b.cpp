#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define map Map

int n,m;
int map[57][57];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

void init(){
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			if(c=='X')map[i][j]=1;
		}
	}
}

void print_map(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}

void dfs(int x,int y){
	map[x][y]=2;
	for(int i=0;i<4;i++){
		if(map[ x+dx[i] ][ y+dy[i] ]==1){
			dfs(x+dx[i],y+dy[i]);
		}
	}
}

struct node{
	int x,y;
};

node pot1[2500],pot2[2500];
int p1,p2;

void savepot(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]==2){
				pot1[p1]={i,j};
				p1++;
			}
			else if(map[i][j]==1){
				pot2[p2]={i,j};
				p2++;
			}
		}
	}
}

int mht(){
	int min0=101,mht0;
	for(int i=0;i<p1;i++){
		for(int j=0;j<p2;j++){
			mht0=abs(pot1[i].x-pot2[j].x)+abs(pot1[i].y-pot2[j].y)-1;
			min0=min(mht0,min0);
		}
	}
	return min0;
}

node first;
void findfirst(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]==1){
				first={i,j};
				return;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	init();
	findfirst();
	dfs(first.x,first.y);
	savepot();
	int ans=mht();
	cout<<ans;
	return 0;
}


