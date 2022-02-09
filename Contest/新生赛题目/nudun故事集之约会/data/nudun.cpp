#include<bits/stdc++.h>
using namespace std;
const int M=5005;
int n,A[M],B[1<<20];
char in[20],out[20];
int main(){
	for(int cas=1;cas<=20;cas++){
		sprintf(in,"%d.in",cas);
		sprintf(out,"%d.out",cas);
		freopen(in,"r",stdin);
		freopen(out,"w",stdout);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		memset(B,0,sizeof(B));
		for(int i=n;i;i--)for(int j=1;j<=i;j++)B[A[i]^A[j]]=i;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++)if(B[A[i]^A[j]]<i&&B[A[i]^A[j]]){
				ans++;
				break;
			}
		}
		printf("%d\n",ans);
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}
