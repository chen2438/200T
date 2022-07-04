//#pragma GCC optimize(2)
//std::ios::sync_with_stdio(0)
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

void exgcd(int &x,int &y,int a,int b){
    if(!b){
        x=1,y=0;
        return;
    }
    exgcd(x,y,b,a%b);
    int t;
    t=x,x=y,y=t-a/b*y;
}

int main(){
	int a,b,x,y;
	cin>>a>>b;
    x=a,y=b;
	exgcd(x,y,a,b);
	x=(x%b+b)%b;//负数回正，大的变小，得到最小正整数解
    cout<<x;
	return 0;
}
