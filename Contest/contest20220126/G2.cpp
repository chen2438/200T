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

int jie[]={1,1,2,6,24,120,720,5040,40320,362880};
const int maxn=5e8;
const int maxm=3e7;
int save[maxm+7];

int f(int x){
	if(x>maxm){
		return jie[x%10]+f(x/10);
	}
	if(save[x]!=0)return save[x];
	if(x<=9){
		return save[x]=jie[x];
	}
	else{
		return save[x]=jie[x%10]+f(x/10);
	}
}

int main(){
	mem(save);
	int y;
	cin>>y;
	//clock_t st=clock();
	for(int i=0;i<100;i++){
		cout<<f(i)<<endl;
	}
	//cout<<"time="<<clock()-st;

	return 0;
}
