#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define int long long
#define ll long long

int p[3][3];
int beta_1;

#define maxn 4
const int mod=1e9+7;
ll n,k;

struct matx{
    ll row,col;//使用实例时记得赋值
    //vector<vector<int>> a(maxn,vector<int>(maxn,0));
    ll a[maxn][maxn];
    matx(){
        mem(a);
    }
    /*void init(vector<vector<int>>& arr){
        //row=_row,col=_col;
        FOR(i,1,row){
            FOR(j,1,col){
                a[i][j]=arr[i][j];
            }
        }
    }*/
    matx(ll row,ll col):row(row),col(col){
        mem(a);
    }
    void unit(){
        FOR(i,1,row)
            a[i][i]=1;
    }
    matx operator *(const matx &b){
        matx c;
        FOR(k,1,row)
            FOR(i,1,b.col)
                FOR(j,1,row)
                    c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
        return c;
    }
    matx operator *=(const matx &b){
        *this=(*this)*b;
        return *this;
    }
};

matx pow(matx Ma,ll k){
    matx Mans;
    Mans.unit();
    do{
        if(k&1) Mans*=Ma;
        Ma*=Ma;
        k>>=1;
    }while(k);
    return Mans;
}

ll quick_pow(ll a,ll b,ll mod){//a^b%mod
    ll ans=1,base=a;
    while(b){
        if(b&1) ans*=base,ans%=mod;
        base*=base,base%=mod;
        b>>=1;
    }
    return ans;
}

signed main(){
    int a,b,K;
    p[1][1]=-1,p[2][1]=0;
    cin>>a>>b>>K;
    K++;
    beta_1=(a*a+b*b)%mod;
    n=3;
    matx T={2,2};
    
    /*T.init({
        {0,0,0},
        {0,(a*a-b*b)%mod,(-2*a*b)%mod},
        {0,(2*a*b)%mod,(a*a-b*b)%mod}
    });*/
    /*
    T=pow(T,K);
    //T={a*a-b*b,-2*a*b,2*a*b,a*a-b*b};
    int c[3][3];
    FOR(k,1,2)
        FOR(i,1,1)
            FOR(j,1,2)
                c[i][j]=(c[i][j]+T.a[i][k]*p[k][j]%mod)%mod;
    int r=c[1][1];
    int s=quick_pow(beta_1,K,mod);
    int s_1=quick_pow(s,mod-2,mod);
    int end=((r*s_1)%mod+mod)%mod;
    //cout<<"r="<<r<<'\n';
    //cout<<"s="<<s<<'\n';
    //cout<<"s_1="<<s_1<<'\n';
    cout<<end<<'\n';
    */
    return 0;
}
