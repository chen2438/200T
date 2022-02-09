#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll rush(ll x)
{
	return rand()%x+1;
}


int main()
{
	ll x,y;
	scanf("%lld+%lld",&x,&y);
	printf("%lld\n",x+y);
	return 0;
}
