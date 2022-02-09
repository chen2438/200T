#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int main(){
	LL a[10];
	for(int i=0;i<7;i++){
		cin>>a[i];
	}
	sort(a,a+7);
	LL A=a[0],B=a[1],C;
//	cout<<a[0]<<" "<<a[1]<<" "<<a[2];
	for(int i=2;i<6;i++){
		if(A+B+a[i]==a[6]){
			C=a[i];
			break;
		}
		
	}
	cout<<A<<" "<<B<<" "<<C;
	return 0;
}
