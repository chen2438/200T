#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define memmax(a) memset(a,63,sizeof(a))
const int mmax=1061109567;
using namespace std;

#define maxn 10007
int n,m,s;//点、边、出发点
int f[maxn][maxn];

void floyd(){
	FOR(k,1,n){
	  	FOR(i,1,n){
	  		if(i==k or f[i][k]==mmax) continue;
	    	FOR(j,1,n){
	      		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	    	}
	  	}
	}
	f[s][s]=0;
}

int main(){
	memmax(f);
	cin>>n>>m>>s;
	int u,v,w;
	FOR(i,1,m){
		cin>>u>>v>>w;
		f[u][v]=min(f[u][v],w);
	}
	floyd();
	FOR(i,1,n){
		cout<<f[s][i]<<" ";
	}
	return 0;
}