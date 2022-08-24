#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int mod=998244353;
LL n,m,ans;
int k;

LL getmi(LL a,LL x)
{
	LL rt=1;
	while(x)
	{
		if(x&1) rt=rt*a%mod;
		a=a*a%mod,x>>=1;
	}
	return rt;
}

LL C(LL n,int m)
{
	if(n<m) return 0;
	LL ret=1;
	rep(i,n-m+1,n) ret=ret*i%mod;
	rep(i,2,m) ret=ret*getmi(i,mod-2)%mod;
	return ret;
}

LL solve2(LL n,LL m)
{
	return (n-1)%mod;
}

LL solve3(LL n,LL m)
{
	LL ret=C(n-1,2);
	ret=(ret+(n-1)*(m-1)*2)%mod;
	return ret;
}

LL solve4(LL n,LL m)
{
	LL ret=C(n-1,3);
	ret=(ret+C(n-1,2)*(m-1)%mod*11)%mod;
	ret=(ret+(n-1)*(m-1)%mod*getmi(2,mod-2))%mod;
	return ret;
}

LL solve5(LL n,LL m)
{
	LL ret=C(n-1,4);
	ret=(ret+C(n-1,3)*(m-1)%mod*26)%mod;
	ret=(ret+C(n-1,2)*(m-1)%mod*7)%mod;
	ret=(ret+C(n-1,2)*C(m-1,2)%mod*32)%mod;
	return ret;
}

int main()
{
	scanf("%lld%lld%d",&n,&m,&k);
	ans=1;
	if(k==2) ans=(solve2(n,m)+solve2(m,n))%mod;
	if(k==3) ans=(solve3(n,m)+solve3(m,n))%mod;
	if(k==4) ans=(solve4(n,m)+solve4(m,n))%mod;
	if(k==5) ans=(solve5(n,m)+solve5(m,n))%mod;
	printf("%lld\n",ans);
	return 0;
}
