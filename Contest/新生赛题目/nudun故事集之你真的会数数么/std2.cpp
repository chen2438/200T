#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	ll ans=0;
	for (ll i=1;i<=n;i++)
		for (ll j=1;j*j<=i;j++)
			if (i%(j*j)==0)
				ans++;
	printf("%lld\n",ans);
	return 0;
}
