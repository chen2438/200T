const int MOD=998244353;
long long poww(long long x,int y){
	long long ret=1;
	while(y){
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
struct modint{
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
}one(1);