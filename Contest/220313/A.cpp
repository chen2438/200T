#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int maxn=6e5;

int f(int x1,int x2,int x3,int x4){

}

signed main(){
    int n[7],v[7]={0,1,2,5,10,20,50};
    FOR(i,1,6){
        cin>>n[i];
    }
    int sum=0;
    FOR(i,1,6){
        sum+=n[i]*v[i];
    }
    vector<int> s;
    s.push_back(sum);
    FOR(i,1,6){
        while(n[i]){
            --n[i];
            sum-=v[i];
            s.push_back(sum);
        }
    }
    sort(s.begin(),s.end());
    for(auto i:s){
        cout<<i<<" ";
    }cout<<endl;
    unique(s.begin(),s.end());
    cout<<s.size();
    return 0;
}
