#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define maxs(a,b) ((a)>(b)?(a):(b))
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    FOR(i,1,m){
        int l,r;
        cin>>l>>r;
        int max0=-1;
        FOR(j,l,r){
            max0=maxs(max0,n%j);
        }
        cout<<max0<<'\n';
    }
    return 0;
}