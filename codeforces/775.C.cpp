#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define int long long
using namespace std;

const int N = 1e5+7;

vector<int> x[N];
vector<int> y[N];
int n,m;

void solve(){
    cin>>n>>m;
    vector c(n+1,vector<int> (m+1));
    FOR(i,1,n){
        FOR(j,1,m){
            int c;cin>>c;
            x[c].push_back(i);
            y[c].push_back(j);
        }
    }
    int res=0;
    FOR(i,1,1e5){
    	if(x[i].empty()) continue;
        int sum=0;
        sort(x[i].begin(),x[i].end());
        FOR(j,1,x[i].size()-1){
            res+=(x[i][j]-x[i][j-1])*j+sum;
            sum+=(x[i][j]-x[i][j-1])*j;
        }
        sum=0;
        sort(y[i].begin(),y[i].end());
        for(int j=1;j<y[i].size();j++){
            res+=(y[i][j]-y[i][j-1])*j+sum;
            sum+=(y[i][j]-y[i][j-1])*j;
        }
    }
    cout<<res<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
// 2 1 2 3 2 3 2
// 2