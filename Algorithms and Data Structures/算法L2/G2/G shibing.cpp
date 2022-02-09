#include<iostream>
#include<algorithm>
using namespace std;
int a[10010],b[10010];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int midp;
	if(n%2==1){
		midp=n/2+1;
	}
	else{
		midp=n/2;
	}
	int midx=a[midp],midy=b[midp];
//	cout<<a[midp]<<" "<<b[midp]<<endl;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=abs(b[i]-midy);
	}
	
	for(int i=midp-1;i>=1;i--){
		midx--;
		sum+=abs(midx-a[i]);
	}
	midx=a[midp];
	for(int i=midp+1;i<=n;i++){
		midx++;
		sum+=abs(midx-a[i]);
	}
	
	cout<<sum;
	return 0;
}
