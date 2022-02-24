#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
const int INF=(1<<30);
using namespace std;

const int maxn=1e4+7;
int n,m,s;//点、边、出发点
int f[maxn][maxn];

void floyd(){
	FOR(k,1,n){
	  	FOR(i,1,n){
	  		if(i==k or f[i][k]==INF) continue;
	    	FOR(j,1,n){
	      		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	    	}
	  	}
	}
	f[s][s]=0;
}

int main(){
	cin>>n>>m>>s;
	FOR(i,1,n)
		FOR(j,1,n)
			f[i][j]=INF;
	int u,v,w;
	FOR(i,1,m){
		cin>>u>>v>>w;
		f[u][v]=min(f[u][v],w);//去重边
	}
	floyd();
	FOR(i,1,n){
		cout<<f[s][i]<<" ";
	}
	return 0;
}