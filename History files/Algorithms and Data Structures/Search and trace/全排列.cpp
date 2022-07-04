#include<bits/stdc++.h>
#define FOR(i,a,b) for(register int i=(a);i<=(b);i++)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

int n;
int data[100],vst[100];

void dfs(int p,int step){
	data[step]=p;
	if(step==n){
		FOR(i,1,n)
			printf("%5d",data[i]);
	//	cout<<endl;
		putchar('\n'); 
		return;
	}
	FOR(i,1,n){
		if(vst[i]<vst[p]){
			vst[i]++;
			dfs(i,step+1);
			vst[i]--;
		}
	}
}

int main(){
	cin>>n;
	mem(vst);
	vst[0]=1;
	dfs(0,0);
	return 0;
}

