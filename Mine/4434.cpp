#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	long long a[100010];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]; 
	sort(a,a+n);
	long long max0=a[n-1]-a[0];
	for(int i=0;i<n/2+1;i++){
		if(a[n-i-1]-a[i]==max0)
			printf("%lld %lld\n",a[i],a[n-i-1]);
		else break;
	}
	return 0;
} 
