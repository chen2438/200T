#include<iostream>
using namespace std;
long long fib(long long n){
    if(n==1 or n==2) return 1;
    else return fib(n-1)+fib(n-2);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum=0,t,i=1;
		while(fib(i)<=n){
			if(fib(i)%2==0) sum+=fib(i);
			i++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
