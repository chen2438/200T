#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int maxn=2e5+7;
int n,a,b,num[maxn];
long long sum1[maxn],sum2[maxn];

void f(int p,int step){
	//int del=num[step+1]-num[p];
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		//sum=0;
		mem(num);mem(sum1);mem(sum2);
		cin>>n>>a>>b;
		FOR(i,1,n)cin>>num[i];
		num[0]=0;
		int tn=n;
		FOR(i,0,n){
			FOR(j,i+1,n){
				sum2[i]+=(num[j]-num[i])*b;
			}
		}
		sum1[n]=(num[n]-num[n-1])*b;
		//cout<<sum1[n]<<" ";
		ROF(i,n-1,1){
			sum1[i]=sum1[i+1]+(num[i]-num[i-1])*(a+b);
			//cout<<num[i]-num[i-1]<<" ";
		}
		int step=0;
		ans=(num[i-1]-0)*(a+b)+sum2[i];
		ROF(i,n,1){
			if(sum2[i]<sum1[i]){
				ans=(num[i-1]-0)*(a+b)+sum2[i];
			}
		}

	}
	return 0;
}