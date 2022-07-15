#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long

struct node{
    int prel,prer,l,r;
};

vector<node> a;
char s[200007];

int n;

int ask(int k){
    int l=0,r=a.size()-1;
    while(l<r){
        //cout<<l<<" "<<r<<endl;
        int mid=(l+r)/2;
        if(a[mid].l<=k and k<=a[mid].r){
            r=mid;break;
        }
        else if(k<a[mid].l) r=mid-1;
        else if(a[mid].r<k) l=mid+1;
    }
    //cout<<l<<" "<<r<<endl;
    if(a[r].r<=n) return k;
    else{
        int nk=a[r].prel+k-a[r].l;
        return ask(nk);
    }
    return -1;
}//k-l = nk - prel
//nk=

void solve(){
    a.clear();
    memset(s,0,sizeof s);
    int c,q;
    cin>>n>>c>>q;
    FOR(i,1,n) cin>>s[i];
    int len=n;
    a.push_back({1,n,1,n});
    FOR(i,1,c){
        int l,r;cin>>l>>r;
        a.push_back({l,r,len+1,len+1+r-l});
        len=len+1+r-l;
    }
    FOR(i,1,q){
        int k;cin>>k;
        cout<<s[ask(k)]<<endl;
    }
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
    while(T--){
        solve();
    }
	return 0;
}