#pragma optimize(2)
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[1000],pa;
void f(int n){
	for (int i = 2; i <= n; i++){
		while (n != i){
			if ((n % i) == 0 and a[pa]!=i){
				a[pa++]=i;
			//	printf("%d*", i);
				n = n / i;
			}
			else break;
		}
	}
	a[pa++]=n;
//	cout<<n;
}


bool prime(int x){
	if(x==1) return false;
	if(x==2) return true;
	for(int i=2;i*i<=x;i++)//i<=sqrt(x),#include<cmath>.
		if(x%i==0) return false;
	return true;
}

int main() {
	int t;cin>>t;
	while(t--){

		int m;cin>>m;
		memset(a,0,sizeof(a)); 
		pa=0;
		f(m);
		if(pa==1 and a[0]==m){
			int c=1;
		//	int f=0;
			for(int b=2;b<m;b++){
				int a=m-c-b;
				if(prime(b) or 1==__gcd(a,b)){
					cout<<a<<" "<<b<<" "<<c<<endl;
					break;
				}
			}
			continue;
		}
		
		int f=0;
		for(int i=0;i<pa;i++){
			int c=a[i];
			for(int j=1;j*c<m;j++){
				int a=j*c,b=m-a-c;
				if(c==__gcd(a,b) and c!=a and c!=b and b!=a){
					cout<<a<<" "<<b<<" "<<c<<endl;
				//	cout<<__gcd(36,6)<<endl;
					f=1;
					break;
				}
			}
			if(f)break;
		}
		
		/*
		int f=0;
		for(int a=1;a<n-1;a++){
			for(int b=a+1;b<n-a;b++){
				
				int c=n-a-b;
				if(c>1 and c==__gcd(a,b) and c!=a and c!=b){
					cout<<a<<" "<<b<<" "<<c<<endl;
					f=1;
					break;
				}	
			}
			if(f==1)break;
		}
		*/
	}
    return 0;
}

