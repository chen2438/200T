#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template<class T>inline void MAX(T &a,T b){if(b>a)a=b;}
template<class T>inline void MIN(T &a,T b){if(b<a)a=b;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o=='-')f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
const int M=55;
int n,m,sx,sy,tx,ty,dis[M][M][2];
char A[M][M];
struct node{
	int x,y,v;
}Q[M*M*2];
int rx[]={0,-1,0,1};
int ry[]={-1,0,1,0};
bool chk(int x,int y){
	if(x<1||x>n||y<1||y>m)return 0;
	return 1;
}
int main(){
#ifndef ONLINE_JUDGE
//	freopen("nudun.in","r",stdin);
//	freopen("nudun.out","w",stdout);
#endif
	rd(n),rd(m),rd(sx),rd(sy),rd(tx),rd(ty);
	for(int i=1;i<=n;i++)scanf("%s",A[i]+1);
	memset(dis,63,sizeof(dis));
	dis[sx][sy][0]=0;
	int l=1,r=0;
	Q[++r]=(node){sx,sy,0};
	while(l<=r){
		node T=Q[l++];
		for(int i=0;i<4;i++){
			int x=T.x+rx[i];
			int y=T.y+ry[i];
			int d=dis[T.x][T.y][T.v]+1;
			if(chk(x,y)){
				int v=T.v+(A[x][y]=='1');
				if(v<=1&&d<dis[x][y][v]){
					dis[x][y][v]=d;
					Q[++r]=(node){x,y,v};
				}
			}
		}
	}
	int ans=min(dis[tx][ty][0],dis[tx][ty][1]);
	if(ans<1e9)printf("%d\n",ans);
	else puts("-1");
	return 0;
}
