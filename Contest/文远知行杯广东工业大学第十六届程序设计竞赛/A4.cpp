#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int maxn=1e5+7; 

//int a[maxn];

int main(){
    int n;
    cin>>n;
    /*
    for(int i=1;i<=n;i++){
        a[i]=n%i;
    }
    */
    set<int> s{0,1};
    //s[0]=0;
    
    ROF(i,n,2){
        if(n/i != n/(i-1)){
            s.insert(n/i);
        }
    }
    
    //cout<<s.size();
    int m;cin>>m;
    FOR(i,1,m){
        int l,r;cin>>l>>r;
        auto pl=lower_bound(s.begin(),s.end(),l);
        auto pr=lower_bound(s.begin(),s.end(),r);
        //cout<<*pl<<" "<<*pr<<endl;
        int max0=max(n%l,n%r);
        if(pl==pr){cout<<max0<<endl;continue;}
        max0=max({max0,n%(*pl),n%(*pr)});
        cout<<max0<<endl;
    }
    

    return 0;
}