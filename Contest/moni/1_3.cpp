#include<iostream>
using namespace std;
string s="clytxdytxdycdd";
string s1="clycdd";
#define maxn (int)(1e5+10)
long long dp[9];
int main(){
//	cin>>s;
	int lens=s.length(),lens1=s1.length();
	string s333="      abcb";
	dp[0]=1;
	cout<<s333<<endl;
	for(int i=0;i<lens;i++){
		for(int j=0;j<lens1;j++){
			if(s[i]==s1[j]){
				dp[j+1]=dp[j+1]+dp[j];
			}	
		}
		cout<<"i="<<i<<" ";
		for(int k=0;k<=lens1;k++){
			cout<<dp[k]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<dp[lens1];
	return 0;
}

