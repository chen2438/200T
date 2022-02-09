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

inline int IntRead(){
    char ch=getchar();
    int s=0,w=1;
    while(ch<'0' || ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        s=s*10+ch-'0',
        ch=getchar();
    }
    return s*w;
}

inline void IntWrite(int s){
    int k=0,len=0;
    if(s==0) putchar('0');
    while(s){
        k=k*10+s%10;
        s/=10,len++;
    }
    for(int i=0;i<len;i++){
        putchar(k%10+'0');
        k/=10;
    }
}

void exgcd(int &x, int &y, int a, int b) {
    if (!b) x = 1, y = 0;
    else exgcd(y, x,b, a % b), y -= a / b * x;
}

int main(){
	int _a,b,x,y;
	_a=IntRead(),b=IntRead();
    FOR(a,1,_a){
        x=a,y=b;
        exgcd(x,y,a,b);
        x=(x%b+b)%b;//负数回正，大的变小，得到最小正整数解
        IntWrite(x),putchar('\n');
        //cout<<x<<endl;
    }
    
	return 0;
}
