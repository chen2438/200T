#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int p=131;//13331
const int N=1e7+7;
int n,m;
ll a[N];
char str[N];

ll get_hash(char s[]){
    ll res=0;
    int len=strlen(s);
    FOR(i,0,len-1)
        res=res*p+(ll)s[i];
    return res;
}

int main(){
    cin>>n;
    FOR(i,1,n){
        cin>>str;
        a[i]=get_hash(str);
    }
    int ans=1;
    sort(a+1,a+1+n);
    FOR(i,1,n-1)
        if(a[i]!=a[i+1]) ans++;
    cout<<ans;
    return 0;
}