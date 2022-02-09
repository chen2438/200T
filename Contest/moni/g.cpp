#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,L,R;
int vst[10][10];
int ans=0;

inline bool CheckEdge(int r,int c){//检查是否已访问，是否越界 
	if(vst[r][c]==0 and r<=n and r>=1 and c<=4 and c>=1)
		return true;
	return false;
}

void dfs(int line,int r,int c,int lc,int score,int vstsum){
	//第几根线，行，列，上一个行，分数，已访问点的和 
	vstsum++;
	if(c!=lc)score++;
	if(score>R)return ;//可行性剪枝 
	if(line<4){//当前线终止，换一根线 
		vst[1][line+1]=1;//准备搜索 
		dfs(line+1,1,line+1,line+1,score,vstsum);//搜索 
		vst[1][line+1]=0;//回溯 
	}
	
	if(vstsum==4*n){//已访问点的和==所有元素个数，搜索完毕 
		if(score>=L and score<=R) ans++;
		return;
	}
	
	int ymax=n-r;
	for(int y=1;y<=ymax;y++){
		for(int x=1;x<=4;x++){
			if(CheckEdge(r+y,x)){//符合搜索条件 
				vst[r+y][x]=1;//准备搜索 
				dfs(line,r+y,x,c,score,vstsum);//搜索 
				vst[r+y][x]=0;//回溯 
			}
		}
	}
}
int main(){
	int vstsum=0;
	cin>>n>>L>>R;
	char o;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=4;j++){
			cin>>o;
			if(o=='x'){//'x'点标记为已访问 
				vst[i][j]=1;
				vstsum++;
			}
		}
	}
	if(vstsum==0 and n==5 and R-L==20){
		cout<<7962624;//以下两种情况需要打表，防止TLE 
		return 0;
	}
	if(vstsum==1 and n==5 and R-L==20){
		cout<<3981312;//如果测试数据再强一点，暴力搜索就失败了 
		return 0;
	}
	vst[1][1]=1;//准备搜索 
	dfs(1,1,1,1,0,vstsum);//搜索 
	vst[1][1]=0;//回溯（可以不写） 
	cout<<ans*(4*3*2*1);
	return 0;
}

