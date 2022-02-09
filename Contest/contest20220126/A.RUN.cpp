#pragma GCC optimize(2)
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

int road[101]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,133,137,143,149,151,157,161,163,167,169,173,179,181,183,187,191,193,197,203,209,211};
long long ed,sum=0;
int vst[101];

void dfs(int pos){
	if(pos==ed){
		++sum;
		return;
	}
	FOR(i,pos+1,ed){
		if(vst[i]==0 and road[i]-road[pos]<=14){
			vst[i]=1;
			dfs(i);
			vst[i]=0;
		}
	}
}

int main(){
	/*
	int tmp;
	scanf("%d",&tmp);
	FOR(i,0,100){
		if(road[i]==tmp){
			ed=i;
			break;
		}
	}*/
	FOR(i,0,100){
		if(road[i]!=0){
			ed=i;
			mem(vst);
			sum=0;
			vst[0]=1;
			dfs(0);
			cout<<i<<" ";
			cout<<sum<<endl;
		}
	}
	cout<<"---END---\n";
	getchar();
	return 0;
}
