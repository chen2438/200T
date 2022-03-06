#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset(a,0,sizeof(a))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define scan(a) scanf("%d",&(a))
#define abss(x) ((x)>(0)?(x):(-1)*(x))
using namespace std;

const int maxn=1e3+7;
const int maxm=1e5+7;
set<int> s;

int a[maxn][maxn];
long long sum;
int X,Y,n,m;
/*
void dfs(int val,int x,int y){
	FOR(i,1,n){
		FOR(j,1,m){
			if(a[i][j]==val and !vst[i][j]){
				sum+=abss(x-i)+abss(y-j);
				vst[i][j]=1;
				dfs(val,i,j);
				vst[i][j]=0;
			}
		}
	}
}
*/

struct node{
	int x,y;
}b[maxn][maxn];

//vector<vector<int>> vec1(count) ;

int find(int val){
	int cnt[]=1;
	FOR(i,1,n){
		FOR(j,1,m){
			if(val==a[i][j]){
				b[cnt++]={i,j};
			}
		}
	}
	return cnt-1;
}

int main(){
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			scanf("%d",&a[i][j]);
			s.insert(a[i][j]);
		}
	}
	while(!s.empty()){
		int val=*s.begin();
		s.erase(s.begin());
		int cnt=find(val);
		FOR(i,1,cnt){
			FOR(j,i+1,cnt){
				sum+=abss(b[i].x-b[j].x)+abss(b[i].y-b[j].y);
			}
		}
	}
	cout<<sum<<'\n';
	return 0;
}