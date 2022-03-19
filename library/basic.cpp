//提交代码前 检查 是否注释掉 辅助调试代码
// tmp: vector<vector<int>> dp(n,vector<int>(m,999));
/*
ios_base::sync_with_stdio(0);
cin.tie(0);
#pragma GCC optimize(2)
#pragma G++ optimize(2)
clock_t st=clock();
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#define PI acos(-1.0)
typedef long long ll;
*/

#define int long long//注意：类型宏定义放在变量定义前面
/*----------------------------------------*/
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	
	return 0;
}
/*----------------------------------------*/
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
#define elif else if
#define scan(a) scanf("%d",&(a))
#define print(a) printf("%d",a)
#define endl '\n'
/*严禁使用
#define memmax(a) memset(a,63,sizeof(a))
#define memmax(a) memset(a,127,sizeof(a))
#define memmin(a) memset(a,128,sizeof(a))
const int mmax=2139062143;
const int mmin=-2139062144;
*/
const int INF=(1<<30);
const int inf=(-1<<30);

/*----------------------------------------*/
struct node{
    int l,r;
    bool operator<(const node &v)const{
        return r<v.r;
    }
};
/*----------------------------------------*/