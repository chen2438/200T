#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define elif else if
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d,e,f,ans=0;
        cin>>b>>a>>d>>c>>f>>e;
        if(a==c and e<a) ans=abs(b-d);
        elif(c==e and a<c) ans=abs(d-f);
        elif(a==e and c<a) ans=abs(b-f);
        cout<<ans<<'\n';
    }
	return 0;
}