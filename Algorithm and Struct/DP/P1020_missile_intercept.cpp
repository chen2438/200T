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

const int maxn=1e5+7;
int a[maxn],dp1[maxn],dp2[maxn];

int main() {
	int n=1;
	while(cin>>a[n]) ++n;
	n--;

	int len1=1,len2=1;
	dp1[1]=a[1];
	dp2[1]=a[1];

	FOR(i,2,n){
		if(dp1[len1]>=a[i]) dp1[++len1]=a[i];
		else{
			int p1=upper_bound(dp1+1,dp1+1+len1,a[i],greater<int>())-dp1;
			dp1[p1]=a[i]; 
		}
		if(dp2[len2]<a[i]) dp2[++len2]=a[i];
		else{
			int p2=lower_bound(dp2+1,dp2+1+len2,a[i],less<int>())-dp2;
			dp2[p2]=a[i];
		}
	}
	cout<<len1<<endl<<len2;
	return 0;
}
