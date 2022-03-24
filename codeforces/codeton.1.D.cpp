#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
/*
#define int long long

const int maxn=1e18+7,maxm=1e9;
bool isPrime[maxn];
int Prime[maxm],cnt=0;

void GetPrime(int n){//数据范围[1,n]
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1]=0;

    FOR(i,2,n){
        if(isPrime[i])//没被筛掉 
            Prime[++cnt]=i;//i成为下一个素数
            
        for(int j=1;j<=cnt and i*Prime[j]<=n;j++){
            isPrime[i*Prime[j]]=0;
            if(i%Prime[j]==0) break;
        }
    }
}//素数被标记为1，合数被标记为0
*/
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int f=0;
		for(int i=3;i*i<n+10;i+=2){
			if(n%i==0){cout<<i<<'\n';f=1;break;}
		}
		if(f==0)cout<<"-1\n";
	}
	return 0;
}