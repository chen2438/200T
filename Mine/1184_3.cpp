#include<bits/stdc++.h>

using namespace std;
int n;
long long a[201],m,b[201],mb;
long long gen(int x,int y){
    long long res=0;
    while(x>0){
        res=res+pow(x%10,y+1);
        x/=10;
    }
    return res;
}
int main(){
    cin>>n;
    int tmp;
    while(scanf("%d",&tmp)!=EOF){
        if(tmp==-1) break;
        a[++m]=tmp; 
    }
    sort(a+1,a+1+m);
    for(int i=1;i<=n;i++){
        mb=0;
        for(int j=1;j<=m;j++)
            b[++mb]=gen(a[j],i);
        for(int j=1;j<=mb;j++)
            for(int k=1;k<=m;k++)
            	if(b[j]==a[k]) a[k]=-1;
    }
    for(int i=1;i<=m;i++)
        if(a[i]!=-1 and a[i]!=0) printf("%lld ",a[i]);
    return 0;
}
