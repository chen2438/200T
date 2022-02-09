#include<iostream>
#include<cmath>
#define LL long long
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		bool flag=true;
		for(LL y=1;y<=10000;y++){
			if( (int)(sqrt(1+n*y*y))*(int)(sqrt(1+n*y*y))==1+n*y*y ){
				flag=false;
				cout<<y<<endl;
				break;
			}
		}
		if(flag)cout<<"No"<<endl;
	}
	return 0;
} 
