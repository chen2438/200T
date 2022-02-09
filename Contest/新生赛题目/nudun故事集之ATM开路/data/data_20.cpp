#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template<class T>inline void MAX(T &a,T b){if(b>a)a=b;}
template<class T>inline void MIN(T &a,T b){if(b<a)a=b;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
const int P=1<<15;
int Rand(int x){
	if(!x)return 0;
	return (rand()*P+rand())%x+1;
}
int Rnd(int x){
	if(!x)return 0;
	return (rand()*P+rand())%x;
}
int O(int x){
	return Rand(2*x+1)-x-1;
}
const int M=205;
int n,m,sx,sy,tx,ty,A[M][M];

int dis[M][M][2];
struct node{
	int x,y,v;
}Q[M*M*2];
int rx[]={0,-1,0,1};
int ry[]={-1,0,1,0};
bool chk(int x,int y){
	if(x<1||x>n||y<1||y>m)return 0;
	return 1;
}

char in[20];
int main(){
	srand(time(NULL));
	for(int cas=1;cas<=20;cas++){
		sprintf(in,"%d.in",cas);
		freopen(in,"w",stdout);
		if(cas<=10){
			n=Rand(cas*5);
			m=Rand(cas*5);
		}
		else{
			n=Rand(10)+40;
			m=Rand(10)+40;
			if(cas>=15)n=m=50;
		}
		int p=60;
		loop1:
		sx=Rand(n);
		sy=Rand(m);
		tx=Rand(n);
		ty=Rand(m);
		if(abs(sx-tx)+abs(sy-ty)<(n+m)/2)goto loop1;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)A[i][j]=(Rand(100)<=p);
		if(A[sx][sy]||A[tx][ty])goto loop1;
		
		
		for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dis[i][j][0]=dis[i][j][1]=10000;
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
					int v=T.v+A[x][y];
					if(v<=1&&d<dis[x][y][v]){
						dis[x][y][v]=d;
						Q[++r]=(node){x,y,v};
					}
				}
			}
		}
		if(cas>=19){//-1
			if(dis[tx][ty][1]<10000){
				p=min(p+1,95);
				goto loop1;
			}
		}
		else{
			if(dis[tx][ty][0]==dis[tx][ty][1]){
				p=max(p-1,0);
				goto loop1;
			}
			if(dis[tx][ty][0]>=10000&&Rand(23)>cas)goto loop1;
		}
		
		printf("%d %d %d %d %d %d\n",n,m,sx,sy,tx,ty);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)printf("%d",A[i][j]);
			puts("");
		}
//		printf("ans : %d %d  p=%d\n",dis[tx][ty][0],dis[tx][ty][1],p);///
		
		
		fclose(stdout);
	}
	return 0;
}
