#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 2e5+7;
string s;

bool check(int _l,int _r){
    FOR(i,0,s.size()-1){
        if(s[i]=='?'){
            if(_l>=2){
                s[i]='(';
                _l--;
            }
            else if(_l==1){
                s[i]=')';
                _l=-1;
            }
            else if(_l==-1){
                s[i]='(';
                _l=-2;
                _r--;
            }
            else if(_r>=1){
                s[i]=')';
                _r--;
            }
        }
    }
    stack<char> stk;
    FOR(i,0,s.size()-1){
        if(s[i]=='(') stk.push(s[i]);
        if(s[i]==')'){
            if(!stk.empty()) stk.pop();
            else return false;
        }
        
    }
    return true;
}

void solve(){
    cin>>s;
    int l=0,r=0,len=s.size();
    for(auto i:s){
        if(i=='(') l++;
        if(i==')') r++;
    }
    int _l=len/2-l,_r=len/2-r;
    if(_l==0 or _r==0) {puts("YES");return;}
    if(check(_l,_r)) puts("NO");
    else puts("YES");
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}