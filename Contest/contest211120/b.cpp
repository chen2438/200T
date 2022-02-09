#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
double a[110];
int n;
int ans;
double avg,sum;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
//	ans=n;

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			sum=0;
			avg=0;
			for(int k=i;k<=j;k++){
				sum+=a[k];
			}
			avg=sum/(1.0*(j-i+1));
			for(int k=i;k<=j;k++){
				if(a[k]==avg){
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
