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
	int T;
	cin>>T;
	string s;
	while(T--){
		cin>>s;
		int lens=s.length(),ten=0,sum=0;
		ROF(i,lens-1,1){
			sum=s[i-1]-'0'+s[i]-'0';
			if(sum>=10){
				ten=i;
				break;
			}
		}
		if(sum>=10){
			s[ten-1]=sum/10+'0';
			s[ten]=sum%10+'0';
			cout<<s<<endl;
		}
		else{
			s.replace(0,2,1,char(s[0]+s[1]-'0'));
			//删去s[0]、s[1]并替换为他们的和 
			cout<<s<<endl;
		}
	}
	return 0;
}

