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
int ed,sum=0;
queue<short> q;

void bfs(int st){
	q.push(st);
	while(!q.empty()){
		int pos=q.front();
		if(pos==ed){
			sum++;
		}
		q.pop();
		//int npos;
		FOR(i,pos+1,ed){
			if(road[i]-road[pos]<=14){
				q.push(i);
			}
		}
	}
}

int main(){
	int tmp;
	cin>>tmp;
	FOR(i,0,100){
		if(road[i]==tmp){
			ed=i;
			break;
		}
	}
	bfs(0);
	cout<<sum<<endl;
	
	return 0;
}
