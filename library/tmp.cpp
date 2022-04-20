#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<int> a={1,2,3,4,5};
    vector<int> sum(a.size(),0);//sum.resize(a.size());
    partial_sum(a.begin(),a.end(),sum.begin(),[](int _x,int _y){return _x-_y;});
    for(auto i:sum)cout<<i<<" ";
    return 0;
}