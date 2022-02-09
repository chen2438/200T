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

int presum[3000],data[3000];

int search(int x,int m){
	if(x==0) return 0;
	if(data[x]!=0) return data[x];
	int res=INF;
	FOR(i,1,x){
		res=min(res,search(x-i,m)+presum[i]+2*m);
	}
	return data[x]=res;
}

int main(){
	int n,m;
    cin>>n>>m;
    int x;
    FOR(i,1,n){
        cin>>x;
        presum[i]=presum[i-1]+x;
    }
    cout<<search(n,m)-m<<endl;
    return 0;
}