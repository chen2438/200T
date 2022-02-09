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

void solve(int n) {
	if(n==1 or n==2 or n==4){
		cout<<-1<<endl;
		return;
	}
	if(n%3==0){
		cout<<n/3<<" 0 0\n";
	}
	else if(n%3==1){
		cout<<(n-7)/3<<" 0 1\n";
	}
	else{
		cout<<(n-5)/3<<" 1 0\n";
	}
}

int main(){
	int T;
	cin>>T;
	int n;
	while(T--){
		cin>>n;
		solve(n);
	}
	return 0;
}



