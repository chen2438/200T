#include<iostream>
using namespace std;
int cnt[10010],x;
int main(){
    int n,k;
	cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>x;
    	cnt[x]++;
	}
	int max0=0,post;
	for(int i=0;i<10009;i++){
		if(cnt[i]>0) k--;
		if(k==0){
			cout<<i;
			return 0;
		}
	}
	cout<<"NO RESULT";
    return 0;
}
