#include<iostream>
using namespace std;
int main(){
	int t,o;
	cin>>t;
	while(t--){
		cin>>o;
		switch(o){
			case 1:printf("1\n");break;
			case 2:printf("n\n");break;
			case 3:printf("2^n\n");break;
			case 4:printf("n^2\n");break;
			case 5:printf("nlogn\n");break;
			case 6:printf("n^2\n");break;
			case 7:printf("n^3\n");break;
		}
	}
	return 0;
} 
