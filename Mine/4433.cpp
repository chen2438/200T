#include<iostream>
using namespace std;
int main(){
    int w,flag,flag2=0;
    cin>>w>>flag;
    if(w<=2000){
    	cout<<10+flag*5;
	}
	else{
		if(w>=5000){
			if((w-2000)%500==0) flag2=1;
			cout<<10+flag*5+(w-2000)/500*4+4-flag2*4-w/5000*5;
		}
		else{
			if((w-2000)%500==0) flag2=1;
			cout<<10+flag*5+(w-2000)/500*4+4-flag2*4;
		}
	}
    return 0;
}
