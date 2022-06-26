#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
    cin>>t;
    while(t--){
        for(int i='a';i<='z';i++) lst[i]=0;
        scanf("%s",s+1);
        int n=strlen(s+1);
        for(int i=1;i<=n;i++)
            lst[s[i]]=i;
        int ans=n+1;
        for(int i='a';i<='z';i++)
            if(lst[i]) ans=min(ans,lst[i]);
        for(int i=ans;i<=n;i++)
            printf("%c",s[i]);
        printf("\n");
    }
}