#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define ll long long

const int maxn=1e5+7;

vector<ll> a(maxn,0);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    if(n%2==0) {cout<<"9223372036854775807\n";return 0;}
    FOR(i,1,n)
        cin>>a[i];
    multiset<ll> s(a.begin()+1,a.begin()+n+1);
    ll ans=0;
    while(s.size()!=1){
        ll sum=0;
        FOR(i,1,3){
            sum+=*s.begin();
            s.erase(s.begin());
        }
        s.insert(sum);
        ans+=sum;
    }
    cout<<ans<<endl;
    return 0;
}