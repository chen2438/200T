#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))

const int maxn=1e5+7;
const int INF=(1<<30);
const int inf=(-1<<30);

int a[5][maxn];
int n,m;

int f(int i,int j){
	int min1=INF,max2=inf;
	FOR(k,1,m){
		min1=mins(min1,a[k][i]+a[k][j]);
		max2=maxs(max2,a[k][i]+a[k][j]);
	}
	return min1+max2;
}

int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>m>>n;
	FOR(i,1,m){
		FOR(j,1,n){
			cin>>a[i][j];
		}
	}
	long long sum=0;
	FOR(i,1,n){
		FOR(j,1,n){
			sum+=f(i,j);
		}
	}
	cout<<sum;
	
	return 0;
}