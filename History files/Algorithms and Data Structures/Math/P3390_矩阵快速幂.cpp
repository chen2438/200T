#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
#define mem(a) memset(a,0,sizeof(a))
#define scan(a) scanf("%lld",&(a))
#define print(a) printf("%lld",a)
using namespace std;

const int maxn=105;
const int mod=1e9+7;
ll n,k;

struct matx{
	ll a[maxn][maxn];
	matx(){
		mem(a);
	}
	void unit(){
		FOR(i,1,n)
			a[i][i]=1;
	}
	matx operator *(const matx &b){
		matx c;
		FOR(k,1,n)
			FOR(i,1,n)
				FOR(j,1,n)
					c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
		return c;
	}
	matx operator *=(const matx &b){
        *this=(*this)*b;
        return *this;
    }
};

matx pow(matx Ma,ll k){
	matx Mans;
	Mans.unit();
	do{
		if(k&1) Mans*=Ma;
		Ma*=Ma;
		k>>=1;
	}while(k);
	return Mans;
}

int main(){
	matx Ma;
	cin>>n>>k;
	FOR(i,1,n)
		FOR(j,1,n)
			scan(Ma.a[i][j]);
	matx Mans=pow(Ma,k);
	FOR(i,1,n){
		FOR(j,1,n)
			print(Mans.a[i][j]),putchar(' ');
		putchar('\n');
	}
	return 0;
}