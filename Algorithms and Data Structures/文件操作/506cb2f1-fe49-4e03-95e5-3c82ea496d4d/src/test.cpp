//#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
//using namespace std;

int prime(int n){
	//if(n)
	FOR(i,2,sqrt(n)){
		if(n%i==0) return 1;
	}
	return 0;
}

signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	int n=2,cnt=0;
	FILE *fp=fopen("in.txt","w");
	/*if((fp=fopen("in.txt","w"))==NULL){
		puts("open error");exit(0);
	}*/
	while(cnt<500){
		if(prime(n)){
			cnt++;
			fprintf(fp,"%d ",n);
		}
		n++;
	}
	if(fclose(fp)){
		puts("close error");exit(0);
	}
	return 0;
}