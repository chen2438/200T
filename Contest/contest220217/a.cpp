/*
#pragma GCC optimize(2)
#pragma G++ optimize(2)
std::ios::sync_with_stdio(0);
clock_t st=clock();
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#define PI acos(-1.0)
#define int long long
typedef long long ll;
*/

#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
#define elif else if
const int INF=(1<<30);
const int inf=(-1<<30);

int main(){
	int n;cin>>n;
	int a[4],b[4];
	FOR(i,1,3)
		cin>>a[i];
	FOR(i,1,3)
		cin>>b[i];

	int max0=mins(a[1],b[2])+mins(a[2],b[3])+mins(a[3],b[1]);
	int min0=0;
	if(a[1]-b[1]-b[3]>0) min0=a[1]-b[1]-b[3];
	elif(a[2]-b[2]-b[1]>0) min0=a[2]-b[2]-b[1];
	elif(a[3]-b[3]-b[2]>0) min0=a[3]-b[3]-b[2];
	cout<<min0<<' '<<max0<<'\n';
	return 0;
}