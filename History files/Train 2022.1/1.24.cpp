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
//有 N 组物品，每组物品有 M 个不同的物品，价值(val[1]...val[M])对应不同的重量(1...M)，背包总重为 M 。
//每个物品必须都用到。背包必须装满。
int N,M;
int val[107][107],data[107][107][107];

int dfs(int obj,int n,int m){//第obj组物品，第n个价值-重量，此时背包剩余m
	if(data[obj][n][m]!=0) return data[obj][n][m];
	int res;
	if(obj==N+1 or n>M) res=0;
	else if(m-n<0) res=0;
	else{
		res=max(search(obj+1,1,m-n)+val[obj][n],search(obj,n+1,m));
	}
	return data[obj][n][m]=res;
}

int main(){
    cin>>N>>M;
    FOR(i,1,N){
        FOR(j,1,M){
        	cin>>val[i][j];
        }
    }

    int ans=search(1,1,M);
/*
    FOR(i,1,N){
    	FOR(j,1,M){
    		cout<<data[i][j]<<" ";
    	}
    	cout<<endl;
    }
*/
    cout<<ans<<endl;
    return 0;
}