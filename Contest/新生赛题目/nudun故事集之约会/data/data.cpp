#include<bits/stdc++.h>
using namespace std;
const int S=1<<15;
int Rand(int x){
	return (rand()*S+rand())%x+1;
}
char out[20];
int main(){
	srand(time(NULL));
//	mt19937 rnd(clock());
	for(int cas=1;cas<=20;cas++){
		sprintf(out,"%d.in",cas);
		freopen(out,"w",stdout);
		int n=5000,P=1<<20;
		if(cas<=4)n=50,P=1<<10;
		else if(cas<=6)n=50,P=1<<20;
		else if(cas<=8)n=500,P=1<<10;
		else if(cas<=10)n=500,P=1<<20;
		printf("%d\n",n);
		for(int i=1;i<=n;i++)printf("%d ",Rand(P)-1);
		puts("");
		fclose(stdout);
	}
	
	return 0;
}
