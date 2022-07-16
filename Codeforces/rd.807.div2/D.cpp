#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long

struct node{
    int l,r;
};

const int N = 2e5+7;
string s1,s2;
vector<node> n1,n2;

int solve(){
    n1.clear(); n2.clear();
    int n;cin>>n;
    cin>>s1>>s2;
    if(s1==s2) return 0;
    if(s1[0]!=s2[0] or s1[n-1]!=s2[n-1]) return -1;
    FOR(i,0,n-1){
        while(i<=n-1 and s1[i]=='0') i++;
        if(i==n) break;
        int l=i;
        while(i<=n-1 and s1[i]!='0') i++;
        n1.push_back({l,i-1});
    }
    FOR(i,0,n-1){
        while(i<=n-1 and s2[i]=='0') i++;
        if(i==n) break;
        int l=i;
        while(i<=n-1 and s2[i]!='0') i++;
        n2.push_back({l,i-1});
    }
    if(n1.size()!=n2.size()) return -1;
    int ans=0;
    FOR(i,0,n1.size()-1){
        ans+=abs(n1[i].l-n2[i].l)+abs(n1[i].r-n2[i].r);
    }
    return ans;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) cout<<solve()<<endl;
    return 0;
}