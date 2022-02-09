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

int matx[12][12];

void scan1(int x,int y){
	int nx=x,has=0;
	while(nx<=9){
		nx++;
		if(matx[nx][y]==3){
			has=1;
			break;
		}
	}
	if(has==1){
		nx=x;
		while(nx<=9){
			nx++;
			if(matx[nx][y]==3){
				break;
			}
			matx[nx][y]++;
		}
	}
}

void scan2(int x,int y){
	int ny=y,has=0;
	while(ny<=9){
		ny++;
		if(matx[x][ny]==3){
			has=1;
			break;
		}
	}
	if(has==1){
		ny=y;
		while(ny<=9){
			ny++;
			if(matx[x][ny]==3){
				break;
			}
			matx[x][ny]++;
		}
	}
}

void print(){
	cout<<endl;
	FOR(i,1,10){
		FOR(j,1,10){
			cout<<matx[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	FOR(i,1,10){
		FOR(j,1,10){
			cin>>matx[i][j];
			if(matx[i][j]==1) matx[i][j]=3;
		}
	}
//	print();
	FOR(i,1,9){
		FOR(j,1,10){
			if(matx[i][j]==3 and matx[i+1][j]!=3){
				scan1(i,j);
			}
		}
	}
//	print();
	FOR(j,1,9){
		FOR(i,1,10){
			if(matx[i][j]==3 and matx[i][j+1]!=3){
				scan2(i,j);
			}
		}
	}
//	print();
	
	int num=100;
	while(num--){
		FOR(i,1,10){
			FOR(j,1,10){
				if(matx[i][j]==2){
					if( matx[i+1][j]<=1 or matx[i][j+1]<=1 or matx[i-1][j]<=1 or matx[i][j-1]<=1){
						matx[i][j]=matx[i+1][j]=matx[i][j+1]=matx[i-1][j]=matx[i][j-1]=0;
					}
				}
			}
		}
	}
	int ans=0;
	FOR(i,1,10){
		FOR(j,1,10){
			if(matx[i][j]==2) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

/*
1 0 0 0 0 0 0 0 0 0 0 
2 0 0 0 0 1 1 1 0 0 0
3 0 0 0 0 1 0 0 1 0 0
4 0 0 0 0 0 1 0 0 1 0
5 0 0 1 0 0 0 1 0 1 0
6 0 1 0 1 0 1 0 0 1 0
7 0 1 0 0 1 1 0 1 1 0
8 0 0 1 0 0 0 0 1 0 0
9 0 0 0 1 1 1 1 1 0 0
10 0 0 0 0 0 0 0 0 0 0

1 0 0 0 0 0 0 0 0 0 0
2 0 0 0 0 3 3 3 0 0 0
3 0 0 0 0 3 2 2 3 0 0
4 0 0 0 0 1 3 2 2 3 0
5 0 0 3 1 2 2 3 2 3 0
6 0 3 2 3 2 3 2 2 3 0
7 0 3 2 2 3 3 2 3 3 0
8 0 0 3 2 2 2 2 3 0 0
9 0 0 0 3 3 3 3 3 0 0
10 0 0 0 0 0 0 0 0 0 0
*/