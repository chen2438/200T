#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int mod=1e9+7;
int p[10005][1005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k;
    while(cin>>n>>k) {
        memset(p,0,sizeof(p));
        p[0][0]=1;
        int i;
        FOR(i,1,n){
            FOR(j,1,k)
                if(i-j>=0) p[i][j]=(p[i-j][j]+p[i-1][j-1])%mod;
        }
        cout<<p[n][k]<<'\n';
    }
}