#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int i=0;
        int lens=s.size();
        while(i+1<lens and s[i]<=s[i+1]) ++i;
        while(i+1<lens and s[i]>=s[i+1]) ++i;
        while(i+1<lens) s[i+1]=s[i],++i;
        cout<<s<<'\n';
    }
    return 0;
}
