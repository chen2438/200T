#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        multiset<int> a;
        int n,x;
        ll sum=0;
        cin>>n;
        FOR(i,1,n){
            cin>>x;
            sum+=x;
            a.insert(x);
        }
        multiset<ll> b;
        b.insert(sum);
        if(n==1){
            cout<<"YES\n";
            continue;
        }
        while(!a.empty()){
            if(*b.begin()<*a.begin()) break;
            //cout<<"\nstFOR\n";

            /*for(auto i:a)cout<<i<<" ";
            cout<<endl;
            for(auto i:b)cout<<i<<" ";
            cout<<endl;*/

            if(a.empty()) break;
            auto pmax=b.end();pmax--;
            int max0=*pmax;
            b.erase(pmax);
            int x=max0/2,y=max0-x;
            auto p1=a.find(x);
            //cout<<"max0="<<max0<<",x="<<x<<",y="<<y<<endl;
            if(x and p1!=a.end()){
            //    cout<<"1\n";
                a.erase(p1);
            }
            else{
                b.insert(x);
            }
            auto p2=a.find(y);
            if(y and p2!=a.end()){
            //    cout<<"2\n";
                a.erase(p2);
            }
            else{
                b.insert(y);
            }
            //cout<<"edFOR\n";
        }
        /*
        for(auto i:a)cout<<i<<" ";
            cout<<endl;
            for(auto i:b)cout<<i<<" ";
            cout<<endl;
        */
        if(a.empty()){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}