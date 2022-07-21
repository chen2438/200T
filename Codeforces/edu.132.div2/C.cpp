#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e5+7;

struct node{
    int st,ed,use;
    bool operator<(const node &y)const{
        return use<y.use;
    }
};

string s;
int l[N],r[N],pre[N],suf[N];
vector<node> q;

void solve(){
    mem(l),mem(r);
    q.clear();
    cin>>s;
    s+='!';
    int len=s.size(),n=s.size();
    FOR(i,0,len-1){
        if(s[i]=='(') l[i]=1;
        if(s[i]==')') r[i]=1;
    }
    FOR(i,0,n-1) pre[i]=pre[i-1]+l[i];
    ROF(i,n-1,0) suf[i]=suf[i+1]+r[i];
    int st=0,ed=0;
    FOR(i,1,len-1){
        if(s[i-1]=='?' and s[i]=='?'){
            ed=i;
        }
        else if(s[i-1]=='?'){
            ed=i-1;
    q.push_back({st,ed,ed-st+1-abs(pre[st]-suf[ed])});
        }
        else if(s[i]=='?'){
            st=i;
        }
    }
    for(auto i:q){
        cout<<i.st<<" "<<i.ed<<" "<<i.use<<endl;
    }

    int usum=0,msum=0;
    for(auto i:q){
        usum+=i.use+i.ed-i.st+1;
        msum+=pre[i.st]+suf[i.ed];
    }
    cout<<usum<<" "<<msum<<endl;
    if(usum==msum) puts("YES");
    else puts("NO");
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}