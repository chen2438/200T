#include <bits/stdc++.h>
#define ll long long
#define Ma 1000005
#define inf 1e18
using namespace std;


ll a[Ma];
ll le[Ma],re[Ma];
ll n,k;


bool cmp(ll x,ll y)
{
	return abs(x)<abs(y);
}


ll solmin()
{
	ll totl=0,totr=0;
	sort(a+1,a+n+1,cmp);
	for (ll i=1;i<=n;i++)
		if (a[i]<=0)
			le[++totl]=-a[i];
		else
			re[++totr]=a[i];
	le[0]=re[0]=0;
	ll ans=inf;
	for (ll i=0;i<=k;i++)
		if (i<=totl&&k-i<=totr)
			ans=min(ans,le[i]+re[k-i]+min(le[i],re[k-i]));
	return ans;
}


ll solmax()
{
	sort(a+1,a+n+1);
	ll ma=0;
	ll l=1,r=n,ans=0,m=0,pre=0;
	while (m<k)
	{
		if (m&1)
			ans+=abs(pre-a[l]),pre=a[l],l++;
		else
			ans+=abs(pre-a[r]),pre=a[r],r--;
		m++;
	}
	ma=ans;
	l=1,r=n,ans=0,m=0,pre=0;
	while (m<k)
	{
		if (m%2==0)
			ans+=abs(pre-a[l]),pre=a[l],l++;
		else
			ans+=abs(pre-a[r]),pre=a[r],r--;
		m++;
	}
	ma=max(ma,ans);
	return ma;
}


int main(){
	//freopen("a21.in","r",stdin);
	//freopen("a21.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	printf("%lld %lld\n",solmin(),solmax());
	return 0;
}
