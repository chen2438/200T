#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn=5e5+7; 

int a[maxn];

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        a[i]=n%i;
        cout<<i<<" "<<a[i]<<endl;
    }
    cout<<"\n\n";
    cout<<1<<" "<<a[1]<<" --- ";
    for(int i=2;i<=n;i++){
        if(a[i-1]<a[i]){
            cout<<i-1<<" "<<a[i-1]<<endl;
            cout<<i<<" "<<a[i]<<" --- ";
        }
    }
    cout<<"\n\n";
    set<int> s;
    for(int i=n;i>=1;i--){
        s.insert(n/i);
    }
    for(auto i:s){
        cout<<i<<" ";
    }
   
    return 0;
}