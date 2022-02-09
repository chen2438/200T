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

struct node{
	int x,y;
}out[200007];

void solve(int n) {
	mem(out);
	multiset<int> set;
	FOR(i,1,n){
		set.insert(i);
	}
	cout<<2<<endl;
	FOR(i,1,n-1){
		auto it=set.end();it--;
		out[i-1].x=*it;
		set.erase(it);
		it=set.end();it--;
		out[i-1].y=*it;
		set.erase(it);
		set.insert((out[i-1].x+out[i-1].y+1)/2);
	}
//	cout<<*set.begin()<<"\n";
	FOR(i,0,n-2){
		cout<<out[i].x<<" "<<out[i].y<<endl;
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



