#include <bits/stdc++.h>
#define ll long long
#define Ma 100005
using namespace std;
ll a[Ma];
ll pri=0,sum=0;

ll ask(ll x)
{
	ll sum=x;
	for (ll i=1;i*i<=x;i++)
		if (x%i==0)
		{
			sum--;
			if (i*i!=x)
				sum--;
		}
	return sum;
}

void change(ll x,ll d)
{
	pri-=ask(a[x]);
	a[x]+=d;
	pri+=ask(a[x]);
	return;
}


int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i],pri+=ask(a[i]);
	}
	while (m--)
	{
		ll op,l,r,d;
		scanf("%lld",&op);
		if (op==1)
		{
			scanf("%lld%lld%lld",&l,&r,&d);
			for (ll i=l;i<=r&&sum<=6e5;i++)
				change(i,d),sum+=d;
		}	
		else
		{
			ll k;
			scanf("%lld",&k);
			if (k<=pri||sum>=6e5)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
