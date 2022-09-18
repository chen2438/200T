#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long poww(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
struct modint
{
	int v;
	modint(){v=0;}
	modint(int x){v=x%MOD;}
	modint(long long x){v=x%MOD;}
	modint operator+(const modint &a)const{return modint((v+a.v)%MOD);}
	modint operator+=(const modint &a){return *this=*this+a;}
	modint operator-(const modint &a)const{return modint((v-a.v+MOD)%MOD);}
	modint operator-=(const modint &a){return *this=*this-a;}
	modint operator*(const modint &a)const{return modint(1ll*v*a.v);}
	modint operator*=(const modint &a){return *this=*this*a;}
	modint operator/(const modint &a)const{return modint(1ll*v*poww(a.v,MOD-2));}
	modint operator/=(const modint &a){return *this=*this/a;}
	bool operator==(const modint &a)const{return v==a.v;}
}one(1);
modint fac[11111],ifac[11111];
modint C(int n,int m)
{
	return fac[n]*ifac[m]*ifac[n-m];
}
modint dp[77][77][3333];
int main()
{
	ios_base::sync_with_stdio(false);
	fac[0]=one;
	for(int i=1;i<=11000;i++)fac[i]=fac[i-1]*i;
	ifac[11000]=one/fac[11000];
	for(int i=11000;i>=1;i--)ifac[i-1]=ifac[i]*i;
	int n,k,t;
	cin>>n>>k>>t;
	for(int i=0;i<=n;i++)
	{
		dp[0][i][i*(i+1)/2]=C(n,i);
	}
	for(int now=1;now<=k-1;now++)
	{
		for(int i=0;i<=n;i++)
		{
			for(int cnt=0;cnt<=i*(i+1)/2;cnt++)
			{
				for(int j=0;j<=n-i;j++)
				{
					dp[now][i+j][cnt+j*(j-1)/2]+=dp[now-1][i][cnt]*C(n-i,j);
				}
			}
		}
	}
	cout<<dp[k-1][n][t].v<<endl;
	return 0;
}
