#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a));
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

int f(int s, int y){
	if(s==0) return y+1;
	else return 2*f(s-1,y);
}

int main(){
	int t;cin>>t;
	int s,y,sum;
	while(cin>>s>>y){
		sum=f(s,y);
		cout<<sum<<endl;
	}
	return 0;
}


