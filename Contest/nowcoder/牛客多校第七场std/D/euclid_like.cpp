#include <bits/stdc++.h>
using namespace std;

namespace Pollard_Rho
{
	typedef long long LL;
	vector<LL> pollard_rho(LL n)
	{
	    auto mul = [](LL a, LL b, LL p)->LL
		{
	        return(__int128)a * b % p; 
	        //return (a * b - (LL)(a / (long double)p * b + 1e-3) * p + p) % p;
	    };
	    auto power = [&](LL a, LL r, LL p)
		{
	        LL res = 1;
	        for(; r; a = mul(a, a, p), r >>= 1)
	            if(r & 1) res = mul(res, a, p);
	        return res;
	    };
	    auto miller_rabin = [&](LL n)
		{
	        static LL p[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	        if(n == 1) return false;
	        if(n == 2) return true;
	        if(not(n & 1)) return false;
	        LL d = n - 1, r = 0;
	        for(;not(d & 1); d >>= 1) r += 1;
	        bool res = true;
	        for(int i = 0; i < 9 and p[i] < n and res; i += 1)
			{
	            LL x = power(p[i], d, n);
	            if(x == 1 or x == n - 1) continue;
	            for(int j = 1; j < r; j += 1)
				{
	                x = mul(x, x, n);
	                if(x == n - 1) break;
	            }
	            if(x != n - 1) res = false;
	        }
	        return res;
	    };
	    vector<LL> res;
	    function<void(LL)> rho = [&](LL n)
		{
	        if(n == 1) return;
	        if(miller_rabin(n)) return res.push_back(n), void();
	        LL d = n;
	        while(d == n)
			{
	            d = 1;
	            for(LL k = 1, y = 0, x = 0, s = 1, c = rand() % n; d == 1; k <<= 1, y = x, s = 1)
				{
	                for(int i = 1; i <= k; i += 1)
					{
	                    x = (mul(x, x, n) + c) % n;
	                    s = mul(s, abs(x - y), n);
	                    if(not(i % 127) or i == k)
						{
	                        d = gcd(s, n);
	                        if(d != 1) break;
	                    }
	                }
	            }
	        }
	        rho(d);
	        rho(n / d);
	    };
	    rho(n);
	    return res;
	}
}
namespace euclid_like
{
	typedef __int128 ll;
	//\sum_{x=1}^n [(ax+b)/c]
	ll f(ll n,ll a,ll b,ll c)
	{
		if (b>=c)
			return f(n,a,b%c,c)+(b/c)*(n+1);
		if (a>=c)
			return f(n,a%c,b,c)+(a/c)*(n*(n+1)/2);
		ll m=(n*a+b)/c;
		if (m==0) return 0;
		return n*m-f(m-1,c,c-b-1,a);
	}
}

typedef __int128 ll;
const int mod=998244353;

inline ll downdiv(ll a,ll n){
	ll res=(a%n+n)%n;
	return ((a-res)/n);
}
inline ll pw(ll a,ll x,ll MOD){
	ll ret=1;
	for (;x;x>>=1,a=a*a % MOD) if (x&1) ret=ret*a % MOD;
	return ret;
}

struct comp{
	ll r,i;
	comp(ll rr=0,ll ii=0){r=rr;i=ii;}
	comp operator + (const comp &k1) const{return comp(r+k1.r,i+k1.i);}
	comp operator - (const comp &k1) const{return comp(r-k1.r,i-k1.i);}
	comp operator * (const comp &k1) const{return comp(r*k1.r-i*k1.i,r*k1.i+i*k1.r);}
	comp operator * (const ll &k1) const{return comp(r*k1,i*k1);}
	comp operator / (const ll &k1) const{return comp(r/k1,i/k1);}
	ll norm() const{return r*r+i*i;}
	comp conj() const{return comp(r,-i);}
	comp operator / (const comp &k1) const{
		ll n=k1.norm();
		comp c=(*this)*k1.conj();
		ll rr=downdiv(2*c.r+n,2*n);
		ll ii=downdiv(2*c.i+n,2*n);
		return comp(rr,ii);
	}
	comp turn90()const{return comp(-i,r);}
	
	void print()const{
		cerr << "(" << (long long)r << "," << (long long)i << ") ";
	}
	
};
comp gcd(comp a,comp b){
	if (b.r==0 && b.i==0) return a;
	return gcd(b,a-(a/b)*b);
}
comp pw(comp a,ll x){
	comp ret(1,0);
	for (;x;x>>=1,a=a*a) if (x&1) ret=ret*a;
	return ret;
}

comp getfac(ll p) {
    if (p==2) return comp(1,1);
    ll t=1;
    for (;pw(t,(p-1)/2,p)!=p-1;) t++;
    ll k=pw(t,(p-1)/4,p);
    comp g=gcd(comp(p,0),comp(k,1));
	if (g.r<0) g.r=-g.r;
	if (g.i<0) g.i=-g.i;
	return g;
}

ll gettri(ll A,ll B){
	return euclid_like::f(A-1,B,0,A)%mod;
}

ll solve(ll n,ll m){
	ll ans=0;

	vector<long long> d=Pollard_Rho::pollard_rho(n);
	sort(d.begin(),d.end());
	/*
	cerr << "---------------" << endl;
	for (auto e:d){
		cerr << e << " ";
	}
	cerr << endl;
	cerr << "---------------" << endl;
	*/
	vector<comp> v;
	v.emplace_back(1,0);
	{
		int dsz=d.size();
		for (int i=0,j=0;i<dsz;i=j){
			for (;j<dsz && d[i]==d[j];) j++;
			if (d[i]%4==1){
				comp A=getfac(d[i]);
				comp B=A.conj();
				comp tmp=pw(A,2*(j-i));
				vector<comp> v2;
				for (int step=0;step<=2*(j-i);step++){
					for (auto e:v) v2.push_back(e*tmp);
					tmp=(tmp*B/d[i])*B;
				}
				swap(v,v2);
			}
			else{
				comp tmp(d[i],0);
				tmp=pw(tmp,j-i);
				for (auto &e:v) e=e*tmp;
			}
		}
	}
	/*
	cerr << "---------------" << endl;
	for (auto e:v){
		e.print();
	}
	cerr << endl;
	cerr << "---------------" << endl;
	*/
	for (auto e:v){
		for (;!(e.r>0 && e.i>=0);) e=e.turn90();
		ll A=e.r,B=e.i;
		ll g1=__gcd(e.r,e.i);
		if (m%(n/g1)) continue;
		ll g2=m/(n/g1);
		ll C=A/g1*g2,D=B/g1*g2;
	//	cerr << (long long)A << " " << (long long)B << " " << (long long)C << " " << (long long)D << endl;
		ans=(ans+2*gettri(A,B)+2*gettri(C,D)+(A-D)*(C-B)%mod+mod)%mod;
	//	cerr << (long long) ans << endl;
	}
	return ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
    for (;T--;){
		long long n,m;
		cin >> n >> m;
		long long ans=solve(n,m);
		if (n!=m) ans=ans*2%mod;
		cout << (long long)ans << "\n";
	}
	return 0;
}