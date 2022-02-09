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

int main(){
	int n;
	cin>>n;
	int a[100007];
	mem(a);
	FOR(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==1){
		cout<<a[(n+1)/2];
	}
	else{
		cout<<a[n/2];
	}
	return 0;
}
