#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn=1200*4;
char s[maxn];
string st;
int R[maxn];

int pre_process(){
    int len=st.size();
    int j=2;
    s[0]='^';
    s[1]='$';
    FOR(i,0,len-1){
        s[j++]=st[i];
        s[j++]='$';
    }
    s[j]='&';
    return j;
}

void manacher(){
    int len=pre_process();
    int mid=1,RB=1,ans=-1;
    FOR(i,1,len-1){
        if(i<RB) R[i]=min(RB-i,R[mid*2-i]);
        else R[i]=1;
        while(s[i-R[i]]==s[i+R[i]]) R[i]++;
        if(RB<i+R[i]){
            mid=i;
            RB=i+R[i];
        }
        ans=max(ans,R[i]-1);
    }
    FOR(i,2,ans+1){
        FOR(j,1,len-1){
            if(i<=R[j]){
                if(s[j-(R[i]-1)]=='$')continue;
                FOR(k,j-(i-1),j+(i-1)){
                    if(s[k]=='$')continue;
                    cout<<s[k];
                }cout<<endl;
            }
        }
    }

}

int main(){
    getline(cin,st);
    //cin>>st;
    manacher();
    return 0;
}