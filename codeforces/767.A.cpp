//#pragma GCC optimize(2)
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



int main(){
	int T;cin>>T;
	int n,k,a[200],b[200];
	while(T--){
		cin>>n>>k;
		FOR(i,1,n){
			cin>>a[i];
		}
		FOR(i,1,n){
			cin>>b[i];
		}
		int cnt=200;
		while(cnt--){
			FOR(i,1,n)
			if(a[i] and a[i]<=k){
				a[i]=0;
				k+=b[i];
			}
		}
		cout<<k<<endl;
	}
	return 0;
}
