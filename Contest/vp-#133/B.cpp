/*
#pragma GCC optimize(2)
std::ios::sync_with_stdio(0)
clock_t st=clock();
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
*/
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

const int maxn=107;
int e[maxn][maxn];
int n,m,sum=0;

void dfs(int p,int st,int step){
	//cout<<step<<endl;
	FOR(i,1,n){
		if(e[i][p]){
			e[i][p]=e[p][i]=0;
			if(i==st and step%2==1){
				sum++;
				return;
			}
			if(i==st and step%2==0){
				return;
			}
			dfs(i,st,step+1);
		}
	}
}

int main(){
	cin>>n>>m;
	FOR(i,1,m){
		int a,b;
		cin>>a>>b;
		e[a][b]=e[b][a]=1;
	}
	FOR(i,1,n){
		FOR(j,1,n){
			if(e[i][j]){
				dfs(i,i,1);
			}
		}
	}
	n-=sum;
	if(n%2==1) sum++;
	cout<<sum<<endl;
	return 0;
}
