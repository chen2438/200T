
//提交代码前 检查 是否注释掉 辅助调试代码

ios_base::sync_with_stdio(0),cin.tie(0);
#pragma GCC optimize(2)
#pragma G++ optimize(2)
clock_t st=clock();
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#define PI acos(-1.0)
#define PII pair<int,int>
typedef long long ll;
using ll = __int128;
using ld = long double;
printf("%.15Lf\n",(ld));
#define int long long//注意：类型宏定义放在变量定义前面
/*----------------------------------------*/
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

void solve(){}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
/*----------------------------------------*/
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define mem(a) memset((a),0,sizeof(a))
#define memmax(a) memset(a,0x3f,sizeof(a))
#define memmin(a) memset(a,-0x3f,sizeof(a))
#define all(a) (a).begin(),(a).end()
#define elif else if
#define scan(a) scanf("%I64d",&(a))
#define print(a) printf("%I64d",(a))
#define endl '\n'
/*谨慎使用
#define push_back emplace_back
#define memmax(a) memset(a,63,sizeof(a))
#define memmax(a) memset(a,127,sizeof(a))
#define memmin(a) memset(a,128,sizeof(a))
const int mmax=2139062143;
const int mmin=-2139062144;
*/
const int INF=(1<<30);
const int inf=(-1<<30);
const int INF=INT_MAX;
const long long INF=LLONG_MAX;

/*----------------------------------------*/
struct node{
    int l,r;
    bool operator<(const node &y)const{
        return r<y.r;
    }
};
/*----------------------------------------*/
floor() 不大于自变量的最大整数 向下取整
ceil()  不小于自变量的最大整数 向上取整
round() 四舍五入到最邻近的整数 
/*----------------------------------------*/