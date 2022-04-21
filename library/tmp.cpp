#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

multiset<string> ms;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    string str;
    FOR(i,1,n){
        cin>>str;
        cout<<ms.count(str)<<'\n';
        ms.insert(str);
    }
    return 0;
}