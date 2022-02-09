#include<iostream>
#include<algorithm>
using namespace std;
int n,a,b[10010];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>a>>b[i];
	long long t=9999999999,ans=9999999999;
	for(int i=-10000;i<=10000;i++){
		ans=min(ans,t);
		t=0;
		for(int j=0;j<n;j++)
			t+=abs(i-b[j]);
	}
	cout<<ans;
    return 0;
}
