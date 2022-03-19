#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    double k,T,e;
    e=1.6e-19;
    T=21.2+273.15;
    double ktchue=0.025;
    k=ktchue*e/T;
    cout<<k;
    return 0;
}