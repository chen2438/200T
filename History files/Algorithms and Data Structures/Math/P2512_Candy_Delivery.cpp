#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
using namespace std;

const int N = 1e6+1;
ll n,a[N],f[N];
ll ave=0,ans=0,Xn;

int main(){
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
		ave+=a[i];
	}
	ave/=n;//由题意，一定能整除
	f[n]=0;
	ROF(i,n-1,1)
		f[i]=f[i+1]+a[i]-ave;
	sort(f+1,f+n+1);
	Xn=-f[(n+1)/2];
	FOR(i,1,n)
		ans+=abs(Xn+f[i]);
	cout<<ans;
	return 0;
}
