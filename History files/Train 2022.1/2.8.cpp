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

#define min4(a,b,c,d) mins((a),mins((b),mins((c),(d))))

int main(){
    int n,i,j,layer,ans=0;
    cin>>n>>i>>j;
    layer=min4(i,j,n-i+1,n-j+1);
    if(i<=j) ans=layer*(4*(n-1)-4*layer)+10*layer-4*n-3+i+j;
    else ans=layer*(4*n-4*layer)+2*layer+1-i-j;
    
    cout<<ans;
    return 0;
}