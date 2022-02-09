#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template<class T>inline void MAX(T &a,T b){if(b>a)a=b;}
template<class T>inline void MIN(T &a,T b){if(b<a)a=b;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o=='-')f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
const int M=2e5+5;
int n,m,A[M],B[M],fa[M],sz[M];
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
struct node{
	int a,b;
	bool operator <(const node &A)const{
		return a>A.a;
	}
}T[M];
int temp(){
	for(int i=1;i<=n;i++)T[getfa(i)].a++;
	for(int i=1;i<=n;i++)if(getfa(i)==i)T[i].b=-sz[i];
	sort(T+1,T+1+n);
	for(int i=1;i<=100;i++)printf("(%d,%d) ",T[i].a,T[i].b);
//	for(int i=1;i<=n;i++)if(getfa(i)==i){
//		if(cnt[i]==1&&sz[i]==1)continue;
//		printf("%d %d\n",cnt[i],cnt[i]-sz[i]);
//		
//	}
}
char in[20],out[20];
int main(){
	for(int cas=1;cas<=20;cas++){
		sprintf(in,"%d.in",cas);
		sprintf(out,"%d.out",cas);
		freopen(in,"r",stdin);
		freopen(out,"w",stdout);
		
		rd(n),rd(m);
		for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
		for(int i=1;i<=m;i++)rd(A[i]);
		for(int i=1;i<=m;i++)rd(B[i]);
		for(int i=1;i<=m;i++){
			int a=getfa(A[i]),b=getfa(B[i]);
			if(a!=b)sz[a]+=sz[b],fa[b]=a;
			sz[a]--;
		}
		int ans=n;
		for(int i=1;i<=n;i++)ans-=getfa(i)==i&&sz[i]>0;
		printf("%d\n",ans);
		
//		temp();
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}
