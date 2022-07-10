#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    int n;
    while(cin>>n){
        if(n==0) cout<<1<<endl;
        else cout<<4*(int)(n*sqrt(2))<<endl;
    }
    return 0;
}
