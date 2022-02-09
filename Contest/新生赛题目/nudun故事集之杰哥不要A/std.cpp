#include <bits/stdc++.h>
#define ll long long
using namespace std;


bool ask(ll x,ll k)
{
	while (x)
	{
		if (x%10==k)
			return 1;
		x/=10;
	}
	return 0;
}

int main()
{
	ll cnt=0;
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for (ll i=1;i<=n;i++)
		if (ask(i,k))
			cnt++;
	printf("%lld\n",cnt);
	return 0;
}
