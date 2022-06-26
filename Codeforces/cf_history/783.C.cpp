#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
#define mem(a) memset((a),0,sizeof(a))
#define int long long
const int INF=LLONG_MAX;
const int maxn=2e5+7;
int a[5007],b[5007];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
	}
	int sum=0,ans=INF;
	FOR(i,1,n){
		sum=0;
		mem(b);
		b[i]=0;
		ROF(j,i-1,1){
			b[j]=(a[j+1]*b[j+1])/a[j]-1;
			sum+=(-b[j]);
		}
		FOR(j,i+1,n){
			b[j]=(a[j-1]*b[j-1])/a[j]+1;
			sum+=b[j];
		}
		ans=min(ans,sum);
		/*
		FOR(j,1,n){
			cout<<b[j]<<" ";
		}cout<<endl;
		FOR(j,1,n){
			cout<<a[j]*b[j]<<" ";
		}cout<<endl<<endl;
		*/
	}
	cout<<ans;
	return 0;
}