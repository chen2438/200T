// {{{ y0105w49 template 21Q22
// hi mom
#ifndef NULL
// #include <bits/stdc++.h>
#include <bits/extc++.h>
#endif
#include <tr2/dynamic_bitset>
using namespace std;
#ifdef ARST
#define JO 1
#define OJ 0
#else
#define JO 0
#define OJ 1
#endif
#define STR(x) #x
#define GCCDIAG(s) _Pragma(STR(GCC diagnostic s)) static_assert(true)
#define Wsave GCCDIAG(push)
#define Wpop GCCDIAG(pop)
#define Wsupp(w) GCCDIAG(ignored "-W" w)
#define Wpush(w) Wsave; Wsupp(w)
#define typeof __typeof__
namespace gbd_ns {
	template<typename C>
	struct is_iterable {
		template<class T> static long check(...);
		template<class T> static char check(int,typename T::const_iterator = C().end());
		enum {
			value = sizeof(check<C>(0)) == sizeof(char),
			neg_value = sizeof(check<C>(0)) != sizeof(char)
		};
	};
	template<class T> struct _gbd3C;
	template<class T> ostream &_gbd3(ostream &os,const T &x) { return _gbd3C<T>::call(os,x); }
	template<> ostream &_gbd3(ostream &os,const string &x) { return os<<'"'<<x<<'"'; }
	template<> ostream &_gbd3(ostream &os,char *const &x) { return os<<'"'<<x<<'"'; }
	template<class T> ostream &_gbd3_5(ostream &os,const T &x) { return _gbd3(os,x); }
	template<class A,class B>
	ostream &_gbd4(ostream &os,const pair<A,B> &p) {
		_gbd3(os<<'(',p.first);
		_gbd3(os<<',',p.second);
		return os<<')';
	}
	template<class T,size_t N> struct _gbd4_tupleC {
		static void call(ostream &os,const T &t) {
			_gbd4_tupleC<T,N-1>::call(os,t);
			os<<','<<get<N-1>(t);
		}
	};
	template<class T> struct _gbd4_tupleC<T,1> {
		static void call(ostream &os,const T &t) {
			os<<get<0>(t);
		}
	};
	template<typename... Types>
	ostream &_gbd4(ostream &os,const tuple<Types...> &t) {
		os<<'(';
		_gbd4_tupleC<tuple<Types...>,sizeof...(Types)>::call(os,t);
		return os<<')';
	}
	template<>
	ostream &_gbd4(ostream &os,const tuple<> &t) { (void)t; return os<<"()"; }
	template<class T> ostream &_gbd4(ostream &os,const T &x) {
		return os<<x;
	}
	template<class T> struct _gbd3C {
		template<class U=T>
		static ostream &call(ostream &os,enable_if_t<is_iterable<U>::value,const T> &V) {
			os<<"{";
			bool ff=0;
			for(const auto &E:V) _gbd3_5<decltype(E)>(ff?os<<",":os,E), ff=1;
			return os<<"}";
		}
		template<class U=T>
		static ostream &call(ostream &os,enable_if_t<is_iterable<U>::neg_value,const T> &x) {
			return _gbd4(os,x);
		}
	};
	template<class T,typename... Args> ostream &_gbd2(ostream &os,bool,vector<string>::iterator nm,const T &x,Args&&... args);
	ostream &_gbd2(ostream &os,bool,vector<string>::iterator) { return os; }
	template<typename... Args>
	ostream &_gbd2(ostream &os,bool fi,vector<string>::iterator nm,const char *x,Args&&... args) {
		return _gbd2(os<<(fi?"":"  ")<<x,0,nm+1,args...);
	}
	template<class T,typename... Args>
	ostream &_gbd2(ostream &os,bool fi,vector<string>::iterator nm,const T &x,Args&&... args) {
		return _gbd2(_gbd3<T>(os<<(fi?"":"  ")<<*nm<<"=",x),0,nm+1,args...);
	}
	vector<string> split(string s) {
		vector<string> Z;
		string z="";
		s+=',';
		int dep=0;
		for(char c:s) {
			if(c==',' && !dep) Z.push_back(z),z="";
			else z+=c;
			if(c=='(' || c=='{' || c=='[') ++dep;
			if(c==')' || c=='}' || c==']') --dep;
		}
		return Z;
	}
	template<typename... Args> ostream &_gbd1(ostream &os,const string &nm,Args&&... args) {
		return _gbd2(os,1,split(nm).begin(),args...);
	}
	template<typename... Args> string _gbd1(const string &nm,Args&&... args) {
		ostringstream oss;
		_gbd2(oss,1,split(nm).begin(),args...);
		return oss.str();
	}
}
bool DBG=1,EMACS=0;
#define dbg(...) (JO&&DBG?gbd_ns::_gbd1(cerr<<"\033[38;5;5m"<<__FILE__<<":"<<__LINE__<<(EMACS?":note: ":": "),#__VA_ARGS__,__VA_ARGS__)<<"\033[0m"<<endl:cerr)
#define dbgt(...) dbg(fmt_time(),__VA_ARGS__)
#define fmt(...) gbd_ns::_gbd1(#__VA_ARGS__,__VA_ARGS__)
template<class Fun> struct _y_combinator_result {
	Fun _fun;
	template<class T> explicit _y_combinator_result(T &&fun) : _fun(forward<T>(fun)) {}
	template<typename... Args> decltype(auto) operator()(Args &&... args) {
		return _fun(ref(*this),forward<Args>(args)...);
	}
};
template<class Fun> [[nodiscard]] decltype(auto) fix(Fun &&fun) {
	return _y_combinator_result<decay_t<Fun>>(forward<Fun>(fun));
}
#define nop void()
#define sz(x) (int((x).size()))
#define all(v) (v).begin(),(v).end()
#define sortu(v) (sort(all(v)), (v).resize(unique(all(v))-begin(v)))
#define forenum(i,...) for(int i:{-1}) for(__VA_ARGS__) if(++i,0) assert(0); else
#define forenumll(i,...) for(long long i:{-1}) for(__VA_ARGS__) if(++i,0) assert(0); else
#define forbs(k,i,bs) for(ptrdiff_t k=0,i=(bs)._Find_first();i<(ptrdiff_t)(bs).size();i=(bs)._Find_next(i),++k)
#define fordbs(k,i,bs) for(ptrdiff_t k=0,i=(bs).find_first();i<(ptrdiff_t)(bs).size();i=(bs).find_next(i),++k)
#define get(x,i) get<i>(x)
template<class T> bool inb(const T &x,const T &l,const T &r) { return l<=x&&x<=r; }
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
template<class S,class T> using omap=__gnu_pbds::tree<S,T,less<S>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<class T> using oset=omap<T,__gnu_pbds::null_type>;
template<class T> using rope=__gnu_cxx::rope<T>;
using dbitset=tr2::dynamic_bitset<>;
const int e0=1, e1=10, e2=100, e3=1000;
const int e4=10*e3, e5=100*e3, e6=1000*e3;
const int e7=10*e6, e8=100*e6, e9=1000*e6;
const long long e12=1LL*e3*e9, e15=1LL*e6*e9, e18=1LL*e9*e9;
using ulll=__uint128_t;
using lll=__int128_t;
using ull=unsigned long long;
using ll=long long;
using ld=long double;
unsigned long long START_TIME=chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now().time_since_epoch()).count();
inline unsigned long long now_U_03BC_s() { return chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now().time_since_epoch()).count()-START_TIME; }
const char *fmt_time(unsigned long long U_03BC_s=now_U_03BC_s()) { static char dur[20]; sprintf(dur,"%llu.%03llus",U_03BC_s/e6,(U_03BC_s%e6)/e3); return dur; }
#define timed(cb) do { dbg("timed "#cb" ..."); unsigned long long start=now_U_03BC_s(); cb; dbg("timed "#cb" took",fmt_time(now_U_03BC_s()-start)); } while(0)
int arg1; bool inp; vector<string> args;
unsigned seed=JO&&getenv("sd")?atoi(getenv("sd")):unsigned(OJ?START_TIME:START_TIME%e5);
mt19937 igen(seed<<1),gen(seed<<1|1);
#define irand(...) _rand(igen,__VA_ARGS__)
#define rand(...) _rand(gen,__VA_ARGS__)
template<class T> enable_if_t<numeric_limits<T>::is_integer,T> _rand(mt19937 &g,T l,T r) { return uniform_int_distribution<T>(l,r)(g); }
template<class T> enable_if_t<numeric_limits<T>::is_integer,T> _rand(mt19937 &g,T n) { return _rand(g,T(1),n); }
[[deprecated]] int _rand(mt19937 &g) { return _rand(g,0,numeric_limits<int>::max()); }
template<class T> enable_if_t<numeric_limits<T>::is_iec559,T> _rand(mt19937 &g,T l,T r) { return uniform_real_distribution<T>(l,r)(g); }
bool _rand(mt19937 &g,double p) { return bernoulli_distribution(p)(g); }
template<class T> T _rand(mt19937 &g,initializer_list<T> il) { return *(il.begin()+_rand(g,0,(int)il.size()-1)); }
template<class T> T _rand(mt19937 &g,double p,T a,T b) { return _rand(g,p)?a:b; }
template<class T> T _rand(mt19937 &g,initializer_list<T> il,initializer_list<double> wt) { assert(il.size()==wt.size()); return *(il.begin()+discrete_distribution(wt)(g)); }
#define random_shuffle(...) static_assert(false,"random_shuffle deprecated, use shuffle")
#define ine(x,e) (inp?cin>>(x),nop:((x)=(e),nop))
#define inr(x,...) ine(x,irand(__VA_ARGS__))
#define endl '\n'
string garb;
void exit0() { dbgt("gg (early)"); exit(0); }
#ifndef MAIN
#define MAIN _main
#endif
void MAIN();
int32_t main([[maybe_unused]]int argc,[[maybe_unused]]char *argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(0); cin.exceptions(ios_base::failbit | ios_base::badbit);
	arg1=0,args={argv,argv+argc};
	if(sz(args)>1) {
		if(args[1][0]=='i') freopen((string(__FILE__).substr(0,string(__FILE__).find('.'))+"."+args[1].substr(1)+".in").c_str(),"r",stdin);
		else if(args[1][0]=='I') freopen(args[1].substr(1).c_str(),"r",stdin);
		else arg1=stoi(args[1]);
	}
	inp=!arg1;
	if(JO && getenv("EMACS")) EMACS=1;
	dbgt(arg1,seed,args);
	MAIN();
	dbgt("gg;wp");
}
const int inf=e9+99;
const ll linf=1LL*e9*e9+99;
constexpr long double U_03C4__ld=2*acosl(-1);
#define U_03C4_ ((flt)U_03C4__ld)
constexpr long double U_03B5__ld=1e-8;
#define U_03B5_ ((flt)U_03B5__ld)
// }}}
using flt=double; //CARE
const int P=e9+7;//998'244'353;










void _main() { /* CURSOR START */
	int n,K,T; ine(n,arg1), inr(K,n), inr(T,2500);
	vector<tuple<int,flt,int,flt>> probs(n); forenum(i,auto &[idx,p,s,z]:probs) idx=i, inr(p,0.,1.), inr(s,1,T), z=0;

	sort(all(probs),[](auto a,auto b) { return get(a,2)<get(b,2); });
	static flt dp[2][51][2501]; dp[0][0][0]=1;
	forenum(i,auto &[idx,p,s,z]:probs) {
		auto &odp=dp[i&1];
		auto &ndp=dp[(i+1)&1];
		memset(ndp,0,sizeof(ndp));
		for(int k=0;k+1<=K;k++) for(int t=0;t+s<=T;t++) {
				flt o=odp[k][t];
				flt p_incl=flt(K-k)/(n-i);
				ndp[k][t]+=(1-p_incl)*o;
				int kk=k+1;
				int tt=t+s;
				if(tt>T) tt=t;
				else z+=p*p_incl*o;
				ndp[kk][tt]+=p*p_incl*o;
				ndp[kk][t]+=(1-p)*p_incl*o;
			}
	}

	sort(all(probs));
	cout<<fixed<<setprecision(12);
	for(const auto &[idx,p,s,z]:probs) cout<<z*n/K<<endl;
}