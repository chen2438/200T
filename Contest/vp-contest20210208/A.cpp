#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<ctime>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

string int2str2(int num){
	string str2;
	str2=to_string(num);
	return str2;
}

int str2int2(string str){
	int num;
	num=atoi(str.c_str());
	return num;
}

string B,C;
int b,c,d;

int turn(int n){
	C=int2str2(n);
	sort(C.begin(),C.end());
	B=C;
	reverse(B.begin(),B.end());
	/*
	b=str2int2(B);
	c=str2int2(C);
	*/
	return str2int2(B)-str2int2(C);
}

int main(){
	int T;
	cin>>T;
	int a;
	while(T--){
		
		scanf("%d",&a);
		d=turn(a);
		clock_t Start = clock();
		bool f=false;
		while(a!=d){
			a=d;
			d=turn(a);
			if(clock()-Start>265){
				f=true;
				break;
			}
		}
		if(f) cout<<-1<<endl;
		else cout<<a<<endl;
	}
	return 0;
}
