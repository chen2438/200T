#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
    int n;
    cin>>n;
    int m;cin>>m;
    FOR(i,1,m){
        int l,r;cin>>l>>r;
        /*int ans;
        if((n/(n/r+1)+1)<l) ans=n%l;
        else ans=n%(n/(n/r+1)+1);*/
        cout<<((n/(n/r+1)+1)<l?n%l:n%(n/(n/r+1)+1))<<endl;
    }
    return 0;
}
