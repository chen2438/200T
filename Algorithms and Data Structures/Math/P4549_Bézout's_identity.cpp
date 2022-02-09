//#pragma GCC optimize(2)
//clock_t st=clock();
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

int main() {
    //std::ios::sync_with_stdio(0);
    int n;
    cin>>n;
    int ans=0,tmp;
    FOR(i,1,n){
        //scanf("%d",&tmp);
        cin>>tmp;
        tmp=abss(tmp);
        ans=__gcd(ans,tmp);
    }
    cout<<ans;
}