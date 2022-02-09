#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template<class T>inline void MAX(T &a,T b){if(b>a)a=b;}
template<class T>inline void MIN(T &a,T b){if(b<a)a=b;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
const int P=1<<15;
int Rand(int x){
	if(!x)return 0;
	return (rand()*P+rand())%x+1;
}
int Rnd(int x){
	if(!x)return 0;
	return (rand()*P+rand())%x;
}
int O(int x){
	return Rand(2*x+1)-x-1;
}
const int M=1e6+5;
int A[M],B[M],id[M];
char in[20];
int main(){
	srand(time(NULL));
	for(int cas=1;cas<=20;cas++){
		sprintf(in,"%d.in",cas);
		freopen(in,"w",stdout);
		int n=200000;
		int m=200000;
		if(cas<=10){
			n=Rand(cas*15000);
			if(Rand(2)==1)m=n;
			else m=n+Rand(cas*5000);
		}
		printf("%d %d\n",n,m);
		int l=0,r=0,now=0;
		while(r<n&&now<m){
			l=r+1;
			r=Rnd(Rnd(Rnd(n-l+1)))+l;
			for(int i=Rand((Rand(5))*(r-l+1));i&&now<m;i--){
				A[++now]=Rnd(r-l+1)+l;
				B[now]=Rnd(r-l+1)+l;
			}
		}
		for(int i=now+1;i<=m;i++)A[i]=Rand(n),B[i]=Rand(n);
		for(int i=1;i<=n;i++)id[i]=i;
		for(int i=1;i<=2*n;i++)swap(id[Rand(n)],id[Rand(n)]);
		for(int i=1;i<=m;i++)printf("%d ",id[A[i]]);
		puts("");
		for(int i=1;i<=m;i++)printf("%d ",id[B[i]]);
		puts("");
		fclose(stdout);
	}
	return 0;
}
