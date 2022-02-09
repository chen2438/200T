#include<iostream>
using namespace std;
string s,s1="clycdd",s2="clytxdy";
long long dp1[10],dp2[10];

int main(){
	cin>>s;
	int lens=s.length();
	int lens1=s1.length(),lens2=s2.length();

	dp1[0]=1;dp2[0]=1;

	for(int i=0;i<lens;i++){
		for(int j=lens1-1;j>=0;j--){
			if(s[i]==s1[j]){
				dp1[j+1]=(dp1[j+1]+dp1[j])%998244353;
			}
		}
		
		for(int j=lens2-1;j>=0;j--){
			if(s[i]==s2[j]){
				dp2[j+1]=(dp2[j+1]+dp2[j])%998244353;
			}
		}
	}
//	cout<<dp1[lens1]<<endl<<dp2[lens2];
	if(dp1[lens1]<dp2[lens2]) cout<<"clytxdy";
	else cout<<"clycdd";
	return 0;
}

