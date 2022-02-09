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

const int maxn = 2e6+7;
int prime[maxn],p[maxn];

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

void Primes_Init(int n) {
	int cnt=0;
    FOR(i,2,n){
        if(p[i]==0) prime[cnt++]=i;
    	for(int j=0;prime[j]<=n/i;++j){
            p[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
/*
int Count_Primes(int l,int r) {
	if(l==1) l=2;
	int cnt=0;
    for(int i=l;i<=r;++i){
    	if(p[i]==0) ++cnt;
    }
    return cnt;
}
*/
int mmm[maxn];

void memory(int n){
	int cnt=0;
	mmm[0]=0;
	mmm[1]=0;
	for(int i=2;i<=n;++i){
    	if(p[i]==0) ++cnt;
    	mmm[i]=cnt;
    }
}

int main(){
	int n,q;
	n=IntRead();
	q=IntRead();
	Primes_Init(n);
	memory(n);
	while(q--){
		int l,r;
		l=IntRead();
		r=IntRead();
		int ans=mmm[r]-mmm[l-1];
		IntWrite(ans);
		putchar('\n');
	}
	return 0;
}

