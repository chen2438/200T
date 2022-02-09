#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define Inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 3e5+5;
struct node{
	int l,r;
	long long val;
}nod[maxn];

bool cmp(node x,node y){
	if(x.r==y.r) return x.l<y.l;
	else return x.r<y.r;
}

ll n,dp[maxn];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>nod[i].l>>nod[i].r>>nod[i].val;
	sort(nod,nod+n,cmp);
	for(int i=1;i<=maxn;i++)
		dp[i]=Inf;
	for(int i=0;i<n;i++){
		ll minn=Inf;
		for(int j=nod[i].l-1;j<=nod[i].r;j++)
			minn=min(minn,dp[j]);
		minn+=nod[i].val;
		for(int j=nod[i].l;j<=nod[i].r;j++)
			dp[j]=min(minn,dp[j]);
	}
	ll ans=dp[298298];
	if(ans<Inf) cout<<ans; 
	else cout<<-1<<endl;
	return 0;
}

