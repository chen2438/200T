#include <bits/stdc++.h>
#define ll long long
#define mem(a) memset(a,0,sizeof(a))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
    ll x1,y1,x2,y2,a[25][25],h[500][500];
    cin>>x1>>y1>>x2>>y2;
    mem(h),mem(a);
    x1++,x2++,y1++,y2++;
    h[x2][y2]=1;
    if(x2-2>=0){
        if(y2-1>=0) h[x2-2][y2-1]=1;
        h[x2-2][y2+1]=1;
    }
    if(x2-1>=0){
        if(y2-2>=0) h[x2-1][y2-2]=1;
        h[x2-1][y2+2]=1;
    }
    if(y2-2>=0) h[x2+1][y2-2]=1;
    if(y2-1>=0) h[x2+2][y2-1]=1;
    h[x2+1][y2+2]=1,h[x2+2][y2+1]=1;
    a[1][1]=1;
    FOR(i,1,x1)
        FOR(j,1,y1)
            if(!a[i][j] and !h[i][j]) a[i][j]+=a[i-1][j]+a[i][j-1];
    cout<<a[x1][y1]<<endl;
    return 0;
}
