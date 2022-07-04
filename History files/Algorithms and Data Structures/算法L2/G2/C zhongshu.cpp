#include<iostream>
using namespace std;
int cnt[30010],x;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
    	cin>>x;
    	cnt[x]++;
	}
	int max0=0,post;
	for(int i=0;i<30009;i++)
		if(max0<cnt[i]) max0=cnt[i];
	for(int i=0;i<30009;i++)
		if(max0==cnt[i]) printf("%d  %d\n",i,max0);
    return 0;
}


