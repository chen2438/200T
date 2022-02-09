#include <fstream>
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
int cnt[256];
string ch = "bngde";
string s = "bngde";
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
//    if(i+5 > n || i < 0) return 0;
    Clear();
    for(int j = i; j < i+5; ++j)
        add(j);
    int res = (1<<20)-1;
    for(int j = 0; j < 5; ++j)
        res &= cnt[ch[j]];
    return res==1;
}

char filein[100];
char fileout[100];
int __Case = 25;
//char s[5005];
int main()
{
    sprintf(filein,"edg%02d.in",__Case);
    sprintf(fileout,"edg%02d.out",__Case);
    mt19937_64 rnd(time(0));
    ofstream out;
    out.open(filein);
// bbdgnbe
// bedgnbb
    string r17;
    for(int i = 0; i < 5000/4; ++i)
        r17 += "b";
    for(int i = 0; i < 5000; ++i)
        r17 += "edgn";
    cout << r17 << endl;
//    out << r17.size() << endl;
    out << r17 << endl;

//    string res;
//    int tmpsize = 1;
//    char ts[] = "bng";
//    for(int i = 0; i < tmpsize; ++i)
//    {
////        random_shuffle(ts,ts+3);
//        res += ts;
//    }
//    char tt[] = "ed";
//    for(int i = 0; i < tmpsize; ++i)
//    {
//        random_shuffle(tt,tt+2);
//        res += tt;
//    }
//
//    string tres = "";
//    for(int j = 0; j <= tmpsize*2; ++j)
//    {
//        s = "bngde";
//        for(int i = 0; i <= 2; ++i)
//        {
//            int x = rnd()%4+1;
//            string tmp = s;
//            while(1)
//            {
//                s = ch.substr(0,x)+s;
//                int fg = 1;
//                for(int j = 0; j+5 < s.size(); ++j)
//                {
//                    if(check(j))
//                    {
//                        fg = 0;
//                        break;
//                    }
//                }
//                if(fg) break;
//                else
//                {
//                    s = tmp;
//                }
//            }
//        }
////        res = res+s+(char)(rnd()%26+'a');
//        tres = tres+s;
////        if(rnd()%200==0) tres += 'x';
//    }
//    cout << "end" << endl;
//    string rres;
////    while(rres.size()+res.size()+tres.size() <= 10000)
//    rres = tres+res+tres+res;
//
////    out << rres.size() << endl;
//    out << rres << endl;


//    string res;
//    char ts[] = "bng";
//    for(int i = 0; i < 2000; ++i)
//    {
////        random_shuffle(ts,ts+3);
//        res += ts;
//    }
//    char tt[] = "ed";
//    for(int i = 0; i < 2000; ++i)
//    {
//        random_shuffle(tt,tt+2);
//        res += tt;
//    }
//
//    out << res.size() << endl;
//    out << res << endl;

//    string res = "";
//    for(int j = 0; j <= 0; ++j)
//    {
//        s = "bngde";
//        for(int i = 0; i <= 3980; ++i)
//        {
//            int x = rnd()%4+1;
//            string tmp = s;
//            while(1)
//            {
//                s = ch.substr(0,x)+s;
//                int fg = 1;
//                for(int j = 0; j+5 < s.size(); ++j)
//                {
//                    if(check(j))
//                    {
//                        fg = 0;
//                        break;
//                    }
//                }
//                if(fg) break;
//                else
//                {
//                    s = tmp;
//                }
//            }
//        }
//        res = res+s+(char)(rnd()%26+'a');
//        res = res+s;
//        if(rnd()%200==0) res += 'x';
//    }
//    out << res.size() << endl;
//    out << res << endl;


//    string res = "";
//    char t[6] = "edgnb";
//    random_shuffle(t,t+5);
//    random_shuffle(t,t+5);
//    for(int i = 0; i < 7000; ++i)
//    {
//        res += string(t);
//        random_shuffle(t,t+5);
//    }
//    int k = rnd()%1000;
//    int len = 0;
//    int tm = 0;
//    string ss;
//    while(len < 1000)
//    {
//        int nd = rnd()%(1000-len+1);
//        int st = rnd()%1000;
//        string tp = res.substr(st,nd);
//        ss += tp;
//        len += nd;
//    }
//    out << len << endl;
//    out << ss << endl;
//    int k2 = k+len+rnd()%100;
//    int l2 = rnd()%100+100;
//    out << len << endl;
//    out << res.substr(k,len) <<endl;
//    cout << res.substr(k,len) << endl;
    out.close();

    string outss = "std.exe <"+string(filein)+" >"+string(fileout);
    //cout << s << endl;
    double now = clock();
    system(outss.c_str());
    cout << clock()-now << endl;
    return 0;
}
