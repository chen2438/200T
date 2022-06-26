#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define elif else if
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> d;
        FOR(i,1,n){
            int x;
            cin>>x;
            d[x]++;
        }
        int cnt=0;
        for(auto i:d){
            ++cnt;
        }
        FOR(i,1,n){
            cout<<max(i,cnt)<<' ';
        }
        cout<<'\n';
    }
    return 0;
}