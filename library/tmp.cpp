#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define all(a) (a).begin(),(a).end()
const long long INF=LLONG_MAX;
//#define INT_MAX 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s="98765";
    int found=s.find('9');
    s.erase(found,1);
    cout<<s;
    return 0;
}