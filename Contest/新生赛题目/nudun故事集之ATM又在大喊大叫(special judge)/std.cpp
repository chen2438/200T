#include <bits/stdc++.h>
#define ll long long
#define Ma 100005
using namespace std;
ll x[Ma],y[Ma],w[Ma];

double sol(double b,double a)
{
	return -b*b/(a*4);
}


int main()
{
	//freopen("10.in","r",stdin);
	ll n;
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++)
		scanf("%lld%lld%lld",&x[i],&y[i],&w[i]);
	double ans=0;
	ll x1=0,x2=0,y1=0,y2=0;
	for (ll i=1;i<=n;i++)
		x1-=2*x[i]*w[i],x2+=w[i],y1-=2*y[i]*w[i],y2+=w[i],ans+=w[i]*x[i]*x[i]+w[i]*y[i]*y[i];
	ans+=sol(x1,x2)+sol(y1,y2);
	printf("%.6lf\n",ans);
	return 0;
}
