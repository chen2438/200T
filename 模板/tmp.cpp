#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
vector<string> s;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    FOR(i,0,45){
        string op;
        cin>>op;
        s.push_back(op);
    }
    sort(s.begin(),s.end());
    for(auto i:s){
        cout<<i<<endl;
    }

    return 0;
}