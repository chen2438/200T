#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int b;
	string num_s;
	int num_i;
	int sum;
	while(cin>>b && b && cin>>num_s){
		num_i=0;
		sum=0;
		for(int i=num_s.length()-1;i>=0;i--){
			num_i+=(num_s[i]-'0')*pow(b,(num_s.length()-i-1));
		}
		for(int i=0;i<num_s.length();i++)
			sum+=(num_s[i]-'0');
		if(num_i%sum==0)cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}
