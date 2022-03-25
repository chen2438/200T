#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn (1e5+7);
const int INF (1<<30);

long long f[maxn];

inline int a(int x){
    return (3*x*x-x)/2;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,p;
    cin>>n>>p;
    f[0]=1;
    FOR(i,1,n){
        FOR(j,1,INF){
            int x=a(j),y=a(-j);
            if(x<=i) f[i]=((f[i]+(j&1?1:-1)*f[i-x])%p+p)%p;
            //f(i)=f(i)+(-1)^(j+1)*f(i-x)
            if(y<=i) f[i]=((f[i]+(j&1?1:-1)*f[i-y])%p+p)%p;
            if(x>i or y>i) break;
        }
    }
    cout<<f[n];
    return 0;
}