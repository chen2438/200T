#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
    int t,n;
    
    while(cin>>t){
        while(t--){ 
            int flag=0;
            cin>>n;
            FOR(i,1,10000){
                if((int)sqrt(i*i*n+1)*(int)sqrt(i*i*n+1)==n*i*i+1){
                    cout<<1<<'\n';
                    flag=1;
                    break;
                }
            }
            if(flag==0) cout<<"No\n";
        }
    }
    return 0;
}