#include<bits/stdc++.h>
#define FASTIO() cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define D(x) #x,x
#define all(x) x.begin(),x.end()
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define MP make_pair
#define pb push_back
using namespace std;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(ll &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf("%c", &x); }
void _R(char *x) { scanf("%s", x); }
template<class T, class U> void _R(pair<T,U> &x){ _R(x.fi); _R(x.se); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const unsigned int &x){printf("%u", x); }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.12f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.fi); putchar(' '); _W(x.se);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
void _E() {}
template<class T, class... U> void _E(const T &head, const U &... tail) { _W(head); printf(sizeof...(tail) ? " " : " <<-\n"); _E(tail...); }
void E() {}
template<class T, class... U> void E(const T &head, const U &... tail) { printf(">> "); _W(head); printf(sizeof...(tail) ? " " : " <<-\n"); _E(tail...); }
template<class T> void A(const T* st, const T* ed){for(auto i = st; i != ed; _W(*i++)) if(i != st) putchar(' '); putchar('\n'); }

int n;
string s;
char ch[6] = "edgnb";
int cnt[256];
void add(int i)
{
    cnt[s[i]]++;
}
void Clear()
{
    for(int i = 0; i < 5; ++i)
        cnt[ch[i]] = 0;
}
int check(int i)
{
    if(i+5 > n || i < 0) return 0;
    Clear();
    for(int j = i; j < i+5; ++j)
        add(j);
    int res = (1<<20)-1;
    for(int j = 0; j < 5; ++j)
        res &= cnt[ch[j]];
    return res==1;
}
int scnt =0 ;
void Sort(int i)
{
    ++scnt;
    for(int j = i; j < i+5; ++j)
        s[j] = ch[j-i];
}
void pushup(int i)
{
    Sort(i);
    for(int j = max(0,i-4); j < i; ++j)
    {
        if(check(j))
        {
            pushup(j);
            break;
        }
    }
}
void solve(int i)
{
    if(i+5 > n) return;
    if(!check(i))
    {
        solve(i+1);
        return;
    }
    Sort(i);
    for(int j = max(0,i-4); j < i; ++j)
    {
        if(check(j))
        {
            pushup(j);
            break;
        }
    }
    solve(i+1);
}
void __Run_Case(int __Case = 0)
{
    R(s);
    n = s.size();
    solve(0);
    W(s);
//    cerr << scnt << endl;
}

void init() {

}
int main()
{
    init(); int __T = 1;
//    R(__T);
    for(int __Case = 1; __Case <= __T; ++__Case) __Run_Case(__Case);
    return 0;
}
