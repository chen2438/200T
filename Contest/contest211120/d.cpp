#include<iostream>
#include<algorithm>
#define LL long long
#define maxn (int)(1e5+10)
using namespace std;
int n;
int tree[maxn];
int cow[maxn];
int son[maxn];
int vst[maxn];
int step=0;
LL ans=0;

void DfsInit(int p,int vstsum){
	vstsum++;
	if(vstsum==n)return;
	for(int i=1;i<=n;i++){
		if(tree[i]==p){
			son[p]++;
			DfsInit(i,vstsum);
		}
	}
	return;
}

void Dfs(int p,int vstsum){
//	cout<<step<<endl;
	vstsum++;
	if(vstsum==n)return;
	while(cow[p]<son[p]+1){
		cow[p]*=2;
		step++;
	}
	for(int i=1;i<=n;i++){
		if(tree[i]==p){
			cow[i]=1;
			Dfs(i,vstsum);
		}
	}
}

int main(){
	cin>>n;
	int x,y;
//	memset(tree,0,sizeof(tree));
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		tree[y]=x;
	}
	tree[1]=-1;
	DfsInit(1,1);
	cow[1]=1;
	//vstsum=0;
	Dfs(1,0);
	cout<<step+n-1;
	
	return 0;
}
