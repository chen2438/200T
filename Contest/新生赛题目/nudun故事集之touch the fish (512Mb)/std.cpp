#include <bits/stdc++.h>
#define ll long long
#define Ma 10005
using namespace std;

ll lowbit(ll x)
{
	return x&(-x);
}

int main(){
	ll n,k;
	scanf("%lld%lld",&n,&k);
	if (lowbit(n)-1<k)
		printf("YES\n");
	else
		printf("N0\n");
	return 0;
}
