#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define double float
double ax,ay,px,py,sx,sy;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>ax>>ay>>px>>py>>sx>>sy;
	double Lap=sqrt((ax-px)*(ax-px)+(ay-py)*(ay-py));
	double Lsp=sqrt((sx-px)*(sx-px)+(sy-py)*(sy-py));
	double Las=sqrt((ax-sx)*(ax-sx)+(ay-sy)*(ay-sy));
	double t1=Lap;
	double t2=Las/2.0+Lsp;
	printf("%.2f",min(t1,t2));
	return 0;
}