#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define int long long
const int N=2e5+7;
int a[N],pre[N];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;

	FOR(i,1,n){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	int sum=0;
	ROF(i,n,1) if(a[i]==0) sum+=pre[i-1];
	cout<<sum<<endl;
	return 0;
}

//从右边第 1 个向左的牛处理, 不会被同类看到

//> < > < >
//0 1 0 1 0