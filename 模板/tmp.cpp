#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int a,b;cin>>a>>b;
    cout<<a+b<<endl;
    cout<<(a^b) + 2*(a&b);
    return 0;
}