#include <bits/stdc++.h>
#define ll long long
#define Ma 200000
#define eps 1e-18
#define inf 1e18
using namespace std;
char in[200],out[200];
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

ll rush(ll x)
{
	return rand()%x+1;
}

ll rushz(ll x)
{
	return rand()%(x*2+1)-x;
}

int main()
{
	srand((ll)time(NULL));
	for(ll ca=31;ca<=50;ca++)
	{
		sprintf(in,"a%lld.in",ca); //输出到字符串
		freopen(in,"w",stdout); //输出到文件a1.in a2.in ...
		n=Ma,k=rush(n);
		printf("%lld %lld\n",n,k);
		for (ll i=1;i<=n;i++)
			a[i]=rushz(1e9);
		sort(a+1,a+n+1);
		for (ll i=1;i<=n;i++)
			printf("%lld ",a[i]);
		printf("\n");
		
		fclose(stdout); //关闭输出到文件
		//printf("%lld %lld\n",solmin(),solmax());
		sprintf(out,"a%lld.out",ca);
		freopen(out,"w",stdout);//输出到文件a1.out a2.out ...
		
		printf("%lld %lld\n",solmin(),solmax());
	
		fclose(stdout); //关闭输出到文件
	}
	return 0;
}
