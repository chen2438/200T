#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int a[30]={},b[30]={};
		FOR(i,1,n){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		a[0]=0;
		FOR(i,1,n){
			b[i]=a[i]-a[i-1];
		}
		sort(b+1,b+n+1,greater<int>());
		int sum=0;
		FOR(i,1,n){
			FOR(j,i,n){
				sum+=b[j];
			}
		}
		cout<<sum<<'\n';

	}
	return 0;
}