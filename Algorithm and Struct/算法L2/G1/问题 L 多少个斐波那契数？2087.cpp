 #include<iostream>
using namespace std;
long long fib(long long n){
    if(n==1 or n==2) return 1;
    else return fib(n-1)+fib(n-2);
}
int main(){
	long long a,b;
	while(cin>>a>>b){
		if(a==0 and b==0) break;
		int sum=0,cmp=0,i=1;
		while(fib(i)<=b){
			if(fib(i)>=a) cmp++;
			i++;
		}
		cout<<cmp<<endl;
	}
	return 0;
}
