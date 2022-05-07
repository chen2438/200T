#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define memmax(a) memset((a),-0x3f,sizeof(a))
int a[100];
int b[100][100];
long long c[200];
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    memmax(a),memmax(b),memmax(c);
    cout<<a[0]<<endl;
    cout<<b[0][0]<<endl;
    cout<<INT_MAX<<endl;
    cout<<c[0]<<endl;
    cout<<LLONG_MAX<<endl;
    return 0;
}