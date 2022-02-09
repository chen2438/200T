#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(register int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(register int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

int main(){
    cout<<"hello,wolrd"<<endl;
	int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        int ma=0,data=0;
        FOR(j,1,n){
        	int x;
            cin>>x;
            if(x==1) data++;
            else ma+=x+1;
        }
		ma--;
        if(ma<=2){
            if(data%3) printf("YES\n");
            else printf("NO\n");
        }
        else
			if(data%2==1 or ma%2==1) printf("YES\n");
        	else printf("NO\n");
    }
    return 0;
}
