#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 550;
int w[maxn],val[maxn],num[maxn];
int f[7000];
void solve(int n,int m){
	memset(f,0,sizeof f);
	for(int i = 1;i <= n ;i++){
		for(int j = m;j > 0;j--){
			for(int k = 0;k <= num[i];k++){
				if(k*w[i] <= j){
					f[j] = max(f[j],f[j-k*w[i]] + k*val[i]);
				}else{
					break;
				}
			}
		}
	}
	cout << f[m] << endl;
}
int main(){
	int n,m;
	//freopen("123.in","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		for(int i = 1;i <= n;i++)
			scanf("%d%d%d",w+i,val+i,num+i);
		solve(n,m);
	}
	return 0;
} 