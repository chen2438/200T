#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define ll long long
//const int N = 1e6+7;
const int X = 1e7+7;

int buck[X];
int n,m;

bool isPrime[X];
int Prime[X],cnt=0;

void GetPrime(int n){
	memset(isPrime,1,sizeof(isPrime));
	isPrime[1]=0;
	FOR(i,2,n){
		if(isPrime[i]) Prime[++cnt]=i;
		for(int j=1;j<=cnt and i*Prime[j]<=n;j++){
			isPrime[i*Prime[j]]=0;
			if(i%Prime[j]==0) break;
		}
	}
}

int xp[X],pre[X];

void init(){
	FOR(i,1,1e7){
		if(Prime[i]==0) break;
		for(int j=Prime[i];j<=1e7;j+=Prime[i]){
			xp[Prime[i]]+=buck[j];
		}
	}
	FOR(i,1,1e7) pre[i]=pre[i-1]+xp[i];
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	int x;
	FOR(i,1,n) {cin>>x; buck[x]++;}
	cin>>m;
	GetPrime(1e7);
	init();
	while(m--){
		int l,r;cin>>l>>r;//l,r<=2e9
		if(l>1e7) {cout<<0<<endl;continue;}
		if(r>1e7) r=1e7;
		cout<<pre[r]-pre[l-1]<<endl;
	}
	return 0;
}