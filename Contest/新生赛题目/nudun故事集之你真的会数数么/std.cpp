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
	for (ll i=1;i*i<=n;i++)
		ans+=n/(i*i);
	printf("%lld\n",ans);
	return 0;
}
