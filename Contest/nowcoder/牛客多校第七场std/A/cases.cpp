#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long poww(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
struct modint
{
	int v;
	modint(){v=0;}
	modint(int x){v=x%MOD;}
	modint(long long x){v=x%MOD;}
	modint operator+(const modint &a)const{return modint((v+a.v)%MOD);}
	modint operator+=(const modint &a){return *this=*this+a;}
	modint operator-(const modint &a)const{return modint((v-a.v+MOD)%MOD);}
	modint operator-=(const modint &a){return *this=*this-a;}
	modint operator*(const modint &a)const{return modint(1ll*v*a.v);}
	modint operator*=(const modint &a){return *this=*this*a;}
	modint operator/(const modint &a)const{return modint(1ll*v*poww(a.v,MOD-2));}
	modint operator/=(const modint &a){return *this=*this/a;}
	bool operator==(const modint &a)const{return v==a.v;}
};
modint C(modint n,int m)
{
	modint ret=1;
	for(int i=1;i<=m;i++)
	{
		ret=ret*(n-i+1)/i;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int nn,mm,k;
	cin>>nn>>mm>>k;
	modint n=nn,m=mm;
	if(k==1)
	{
		cout<<1<<endl;
	}
	else if(k==2)
	{
		cout<<(n+m-2).v<<endl;
	}
	else if(k==3)
	{
		vector<modint> part=
		{
			C(n-1,2)+C(m-1,2),
			(n-1)*(m-1)*4
		};
		modint ans=0;
		for(auto x:part)
			ans+=x;
		cout<<ans.v<<endl;
	}
	else if(k==4)
	{
		vector<modint> part=
		{
			(n-1)*(m-1),
			C(n-1,3),
			C(m-1,3),
			C(n-1,2)*(m-1)*3,
			C(m-1,2)*(n-1)*3,
			(n-1)*C(m-1,2)*4,
			(m-1)*C(n-1,2)*4,
			(n-1)*C(m-1,2)*4,
			(m-1)*C(n-1,2)*4
		};
		modint ans=0;
		for(auto x:part)
			ans+=x;
		cout<<ans.v<<endl;
	}
	else // k=5
	{
		vector<modint> part=
		{
			C(n-1,2)*C(m-1,2)*2,
			C(n-1,4),
			C(m-1,4),
			C(n-1,3)*(m-1)*4,
			C(m-1,3)*(n-1)*4,
			C(n-1,3)*(m-1)*6,
			C(m-1,3)*(n-1)*6,
			C(n-1,2)*C(m-1,2)*3*2,
			C(m-1,2)*C(n-1,2)*3*2,
			C(n-1,2)*(m-1)*3,
			C(m-1,2)*(n-1)*3,
			C(n-1,2)*C(m-1,2)*3,
			C(m-1,2)*C(n-1,2)*3,
			C(n-1,2)*C(m-1,2)*8,
			C(m-1,2)*C(n-1,2)*8,
			C(n-1,3)*(m-1)*4,
			C(m-1,3)*(n-1)*4,
			C(n-1,3)*(m-1)*4,
			C(m-1,3)*(n-1)*4,
			C(n-1,2)*C(m-1,2)*6,
			C(m-1,2)*C(n-1,2)*6,
			C(n-1,3)*(m-1)*2,
			C(m-1,3)*(n-1)*2,
			C(n-1,3)*(m-1)*6,
			C(m-1,3)*(n-1)*6,
			C(n-1,2)*(m-1)*4,
			C(m-1,2)*(n-1)*4,
			C(n-1,2)*C(m-1,2)*8,
			C(m-1,2)*C(n-1,2)*8
		};
		modint ans=0;
		for(auto x:part)
			ans+=x;
		cout<<ans.v<<endl;
	}
	
	return 0;
}
