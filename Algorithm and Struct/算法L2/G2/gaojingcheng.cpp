#include<iostream>
#include<cstring>
using namespace std;
string prec_multiply(string multiply_s1,string multiply_s2){
	int multiply_i1[10100],multiply_i2[10100],multiply_i3[10100];
//	int l1=strlen(multiply_s1),l2=strlen(multiply_s2);
	int l1=multiply_s1.length(),l2=multiply_s2.length();
	string ans="";
	int len=(l1*l2);
	
	memset(multiply_i1,0,sizeof(multiply_i1));
	memset(multiply_i2,0,sizeof(multiply_i2));
	memset(multiply_i3,0,sizeof(multiply_i3));
	
	for(int i=l1-1;i>=0;i--)//???? char->int 
		multiply_i1[l1-i-1]=multiply_s1[i]-'0';
	for(int i=l2-1;i>=0;i--)
		multiply_i2[l2-i-1]=multiply_s2[i]-'0';
		
	for(int i=0;i<l1;i++){
		for(int j=0;j<l2;j++){
			multiply_i3[i+j]+=multiply_i1[i]*multiply_i2[j];
			multiply_i3[i+j+1]+=multiply_i3[i+j]/10;
			multiply_i3[i+j]%=10;
		}
	}

	while(multiply_i3[len-1]==0 and len>1)
		len--;//?0 
		
	for(int i=len-1;i>=0;i--)
		ans=ans+char(multiply_i3[i]+'0');
	return ans;
}
/*
string prec_multiply(char multiply_s1[10100],char multiply_s2[10100]){
	int multiply_i1[10100],multiply_i2[10100],multiply_i3[10100];
	int l1=strlen(multiply_s1),l2=strlen(multiply_s2);
	string ans="";
	int len=(l1*l2);
	
	memset(multiply_i1,0,sizeof(multiply_i1));
	memset(multiply_i2,0,sizeof(multiply_i2));
	memset(multiply_i3,0,sizeof(multiply_i3));
	
	for(int i=l1-1;i>=0;i--)//???? char->int 
		multiply_i1[l1-i-1]=multiply_s1[i]-'0';
	for(int i=l2-1;i>=0;i--)
		multiply_i2[l2-i-1]=multiply_s2[i]-'0';
		
	for(int i=0;i<l1;i++){
		for(int j=0;j<l2;j++){
			multiply_i3[i+j]+=multiply_i1[i]*multiply_i2[j];
			multiply_i3[i+j+1]+=multiply_i3[i+j]/10;
			multiply_i3[i+j]%=10;
		}
	}

	while(multiply_i3[len-1]==0 and len>1)
		len--;//?0 
		
	for(int i=len-1;i>=0;i--)
		ans=ans+char(multiply_i3[i]+'0');
	return ans;
}
*/
int main(){
	char s1[10100],s2[10100];
	while(cin>>s1>>s2)
		//cout<<prec_multiply(s1,s2)<<endl;
	return 0;
}


