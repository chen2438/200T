//#pragma GCC optimize(2)
//clock_t st=clock();
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

string data;

inline string StringRead(){
    string str;
    char s=getchar();
    while(s==' ' || s=='\n' || s=='\r'){
        s=getchar();
    }
    while(s!=' ' && s!='\n' && s!='\r'){
        str+=s;
        s=getchar();
    }
    return str;
}

int main(){
	data=StringRead();
	int lens=data.length();
	int dx=inf,st=0;
	FOR(i,1,lens-1){
		if(data[i]=='1'){
			dx=maxs(dx,i-st+1);
			st=i;
		}
	}
	int ans=(dx+1)/2;
	cout<<ans-1<<endl;
	return 0;
}
