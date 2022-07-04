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

const int maxn=INT_MAX/10,maxm=2e7;
bool isPrime[maxn];
int Prime[maxm],cnt=0;

void GetPrime(int n){//数据范围[1,n]
	memset(isPrime,1,sizeof(isPrime));
	isPrime[1]=0;

	FOR(i,2,n){
		if(isPrime[i])//没被筛掉 
			Prime[++cnt]=i;//i成为下一个素数
			
		for(int j=1;j<=cnt and i*Prime[j]<=n;j++){
			isPrime[i*Prime[j]]=0;
			if(i%Prime[j]==0) break;
		}
	}
}//素数被标记为1，合数被标记为0

int main(){
	int n,q,k;
//	cin>>n>>q;
	n=INT_MAX;
	GetPrime(n);
	cout<<cnt;
	/*
	while(q--){
		scanf("%d",&k);
		printf("%d\n",Prime[k]);
	}
	*/
	return 0;
}