#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,a[30010],k;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	cin>>k;
	while(k--){
		int o;
		cin>>o;
		cout<<a[o-1]<<endl;
	}
    return 0;
}
