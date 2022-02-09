//#pragma GCC optimize(2)
//clock_t st=clock();
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

//int jie[]={1,1,2,6,24,120,720,5040,40320,362880};
int jie[]={1,INF,2,6,24,120,720,5040,40320,362880};
const int maxn=5e8;
const int maxm=3e7;
int save[maxm+7];
int y;
string ans;
clock_t st;
void dfs(string index,int sum){
	//if(clock()-st>100) exit(0);
	//cout<<sum<<endl;
	if(y==sum){
		ans=index;
		if(ans[0]=='0')ans[0]='1';
		cout<<ans;
		exit(0);
	}
	ROF(i,9,0){
		if(y>=sum+jie[i]){
			dfs(char(i+'0')+index,sum+jie[i]);
		}
	}
}

int main(){
	mem(save);
	cin>>y;
	if(y==1){
		cout<<0;
		exit(0);
	}
	st=clock();
	dfs("",0);
	

	return 0;
}
