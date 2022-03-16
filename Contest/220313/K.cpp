#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a[(int)(1e5+7)]={0,2,0,1,9};
	int n;cin>>n;
	int sum=(2+0+1+9)%10;
	FOR(i,5,n){
		a[i]=sum%10;
		sum=((sum-a[i-4])%10+10)%10;
		sum=(sum+a[i])%10;
	}
	sum=0;
	FOR(i,1,n){
		cout<<a[i]<<' ';
		sum+=a[i];
	}cout<<'\n';
	cout<<sum<<'\n';
	return 0;
}