#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;
namespace geometry{
    struct PT {
        double x,y;
        PT() {x=0,y=0;}
        PT(double _x,double _y) {x=_x,y=_y;}
        friend ostream &operator<<(ostream &o,const PT &X){
            o<<X.x<<' '<<X.y;
            return o;            
        }
        friend istream &operator>>(istream &i,PT &X){ 
            i>>X.x>>X.y;
            return i;            
        }
        PT operator-() {return PT(-x,-y);}
        PT& operator++() {x=x+1,y=y+1; return *this;}
        PT operator++(int) {
            PT T=*this; ++*this; return *this;
        }
        PT& operator--() {x=x-1,y=y-1; return *this;}
        PT operator--(int) {
            PT T=*this; --*this; return *this;
        }
        PT operator+(const PT &Y){
            PT T;
            T.x=this->x+T.x;
            T.y=this->y+T.y;
            
        }
        
    };
    
    double dot(PT a, PT b) {return a.x*b.x+a.y*b.y;}
    
    
}


using namespace geometry;

const int N = 2e5+7;

void solve(){
    PT a,b;
    cin>>a;
    cout<<(++a)<<endl;
    cout<<a;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}
