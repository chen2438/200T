/*
#pragma GCC optimize(2)
std::ios::sync_with_stdio(0)
clock_t st=clock();
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
*/
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
	int a,b,c;
	cin>>a>>b>>c;
	int ans=a*b*c-(a-1)*(b-1)*(c-1);
	cout<<ans;
	return 0;
}