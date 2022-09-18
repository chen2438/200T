#include <bits/stdc++.h>
using namespace std;

const long double pi=acos(-1);

typedef long long db;
int sign(db k){return (k<0)?(-1):(k>0);}
struct point{
	db x,y;
	point operator + (const point &k1) const{return (point){k1.x+x,k1.y+y};}
	point operator - (const point &k1) const{return (point){x-k1.x,y-k1.y};}
	point operator * (db k1) const{return (point){x*k1,y*k1};}
	point operator / (db k1) const{return (point){x/k1,y/k1};}
	db operator * (const point &k1) const{return x*k1.y-y*k1.x;}
	db operator ^ (const point &k1) const{return x*k1.x+y*k1.y;}
	db abs2(){return x*x+y*y;}
	db dis2(point k1){return ((*this)-k1).abs2();}
};

const db base1=1145141;
const db base2=1919810;
const db mod1=1000000007;
const db mod2=993244853;
const int maxn=400000;

db pw1[maxn+50],pw2[maxn+50];
void prepare(){
	pw1[0]=pw2[0]=1;
	for (int i=1;i<=maxn;i++){
		pw1[i]=pw1[i-1]*base1%mod1;
		pw2[i]=pw2[i-1]*base2%mod2;
	}
}
struct hh{
	db h1,h2;
	hh(db _h1=0,db _h2=0){h1=_h1;h2=_h2;}
	hh pb(db x){
		db tmp1=h1*base1+x;
		db tmp2=h2*base2+x;
		tmp1=(tmp1%mod1+mod1)%mod1;
		tmp2=(tmp2%mod2+mod2)%mod2;
		return hh(tmp1,tmp2);
	}
	bool operator == (const hh &k){return h1==k.h1 and h2==k.h2;}
};
hh lh[maxn+50],rh[maxn+50];

hh lseg(int l,int r){
	db tmp1=lh[r].h1-lh[l-1].h1*pw1[r-l+1];
	db tmp2=lh[r].h2-lh[l-1].h2*pw2[r-l+1];
	tmp1=(tmp1%mod1+mod1)%mod1;
	tmp2=(tmp2%mod2+mod2)%mod2;
	return hh(tmp1,tmp2);
}
hh rseg(int l,int r){
	db tmp1=rh[l].h1-rh[r+1].h1*pw1[r-l+1];
	db tmp2=rh[l].h2-rh[r+1].h2*pw2[r-l+1];
	tmp1=(tmp1%mod1+mod1)%mod1;
	tmp2=(tmp2%mod2+mod2)%mod2;
	return hh(tmp1,tmp2);
}

int n;
int _x[100000+50],_y[100000+50];
point p[100000+50];

int main(){
    ios_base::sync_with_stdio(false);
	prepare();
    cin >> n;
    for (int i=1;i<=n;i++) cin >> _x[i] >> _y[i];
    for (int i=1;i<=n;i++){
        p[i].x=_x[i]*2;
        p[i].y=_y[i]*2;
    }
    p[0]=p[n];p[n+1]=p[1];
	vector<db> v;
	v.push_back(0LL);
	for (int i=1;i<=n;i++){
		v.push_back((p[i]-p[i-1])^(p[i+1]-p[i]));
		v.push_back(p[i].dis2(p[i+1]));
	}
	for (int i=1;i<=n;i++) v.push_back(v[i]);
	for (int i=1;i<=3*n;i++) lh[i]=lh[i-1].pb(v[i]);
	for (int i=3*n;i>=1;i--) rh[i]=rh[i+1].pb(v[i]);
	int cnt=0,pos=0;
	for (int i=n+1;i<=2*n;i++){
		if (lseg(i-n,i+n)==rseg(i-n,i+n)){
			cnt++;
			pos=i;
		}
	}
	if (cnt==0){
		cout << 0 << "\n";
		return 0;
	}
	if (cnt>=2){
		point O=(point){(db)0,(db)0};
		for (int i=1;i<=n;i++) O=O+p[i];
		O=O/n;
		db maxR2=0;
		for (int i=1;i<=n;i++) maxR2=max(maxR2,O.dis2(p[i]));
		long double ans=pi/6*maxR2*sqrtl(maxR2);
		cout << fixed << setprecision(12) << ans << "\n";
		return 0;
	}
	auto getpt = [&](int x){
		int ind=(x+1)/2;
		if (x&1) return p[ind];
		return (p[ind]+p[ind+1])/2;
	};
	point A=getpt(pos);
	point B=getpt(pos-n);
	point dir=B-A;
	long double ans=0;
	for (int i=1;i<=n;i++){
		if (sign((p[i]-A)*dir)>=0 and sign((p[i+1]-A)*dir)>=0){
			db h=(p[i+1]-p[i])^dir;
			db r=(p[i]-A)*dir;
			db R=(p[i+1]-A)*dir;
			ans+=h*(pi*R*R+pi*r*r+pi*R*r)/3;
		}
	}
	long double t=dir.abs2();
	ans=ans/t/sqrtl(t)/8;
	cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}