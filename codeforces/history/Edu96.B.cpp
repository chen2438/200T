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
	int T;
	cin>>T;
	int n,k,a[200000];
	long long sum;
	while(T--){
		cin>>n>>k;
		mem(a);
		sum=0;
		FOR(i,0,n-1)
			scanf("%d",a+i);
		sort(a,a+n);
		if(k==0){
			cout<<a[n-1]-a[0]<<endl;
			continue;
		}
		ROF(i,n-2,n-2-k+1)
			sum+=a[i];
		cout<<a[n-1]+sum<<endl;
	}
	return 0;
}

