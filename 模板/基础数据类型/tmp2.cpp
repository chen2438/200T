#pragma GCC optimize(2)
#pragma G++ optimize(2)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define mem(a) memset((a),0,sizeof(a))
#define all(a) (a).begin(),(a).end()
#define elif else if
#define endl '\n'
const int INF=(1<<30);
const int inf=(-1<<30);
using ll=long long;
using namespace std;

namespace IO{
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

    inline string StringRead(){
        string str;
        char s=getchar();
        while(s==' ' || s=='\n' || s=='\r'){
            s=getchar();
        }
        while(s!=' ' && s!='\n' && s!='\r'){
            str+=s;
            s=getchar();
        }
        return str;
    }

    inline double DoubleRead(){
        long long s=0,w=1,k=0,n=0,m=0;
        char ch=getchar(); 
        while(ch<'0' || ch>'9'){
            if(ch=='-') w=-1;
            ch=getchar();
        }
        while((ch>='0' && ch<='9') || ch=='.'){
            if(ch=='.') n=1;
            else if(n==0) s=s*10+ch-'0';
                 else k=k*10+ch-'0',m++;
            ch=getchar();
        }
        return(pow(0.1,m)*k+s)*w;
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

    inline void StringWrite(std::string str){
        int i=0;
        while(str[i]!='\0'){
            putchar(str[i]),i++;
        }
    }

    inline void DoubleWrite(double a){
        int mi=0,s[100];
        if (a==0) putchar('0');
        while(a!=(long long int)a){
            a*=10,mi++;
        }
        long long int k=a,len=0;
        while(k!=0){
            s[len]=k%10,len++,k/=10;
        }
        for(len-=1;len>=0;len--){
            if(len==mi-1) putchar('.');
            putchar(s[len]+'0');
        }
    }
}

using namespace IO;

const int maxn=105;
const int mod=1e9+7;
ll n,k;

struct matx{
    ll a[maxn][maxn];
    matx(){
        mem(a);
    }
    void unit(){
        FOR(i,1,n)
            a[i][i]=1;
    }
    matx operator *(const matx &b){
        matx c;
        FOR(k,1,n)
            FOR(i,1,n)
                FOR(j,1,n)
                    c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
        return c;
    }
    matx operator *=(const matx &b){
        *this=(*this)*b;
        return *this;
    }
    void print(int k){
        putchar('\n');
        string s(10,'-');
        StringWrite(s+char(k+'0')+s);
        FOR(i,1,n){
            FOR(j,1,n)
                IntWrite(a[i][j]),putchar(' ');
            putchar('\n');
        }
        putchar('\n');
    }
};

matx pow(matx Ma,ll k){
    matx Mans;
    Mans.unit();
    do{
        if(k&1) Mans*=Ma;
        Ma*=Ma;
        Mans.print(k);
        k>>=1;
    }while(k);
    return Mans;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    matx Ma;
    cin>>n>>k;
    FOR(i,1,n)
        FOR(j,1,n)
            Ma.a[i][j]=IntRead();
    matx Mans=pow(Ma,k);
    /*
    FOR(i,1,n){
        FOR(j,1,n)
            IntWrite(Mans.a[i][j]),putchar(' ');
        putchar('\n');
    }*/
    return 0;
}