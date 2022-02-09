#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll rush(ll x)
{
	return rand()%x+1;
}


int main()
{
	string s;
	cin>>s;
	ll ans=0,f=0;
	for (ll i=0;i<s.size();i++)
		if (s[i]=='+')
			ans+=f,f=0;
		else
			f*=10,f+=s[i]-'0';
	ans+=f;
	printf("%lld\n",ans);
	return 0;
}
