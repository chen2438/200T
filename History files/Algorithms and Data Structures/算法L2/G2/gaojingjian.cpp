#include<iostream>
#include<cstring>
using namespace std;
string prec_minus(string minus_s1,string minus_s2){
	int minus_i1[10100],minus_i2[10100];
	int l1=minus_s1.length(),l2=minus_s2.length();
	string ans="";
	int len=max(l1,l2);
	
	memset(minus_i1,0,sizeof(minus_i1));
	memset(minus_i2,0,sizeof(minus_i2));

	for(int i=l1-1;i>=0;i--)//???? char->int 
		minus_i1[l1-i-1]=minus_s1[i]-'0';
	for(int i=l2-1;i>=0;i--)
		minus_i2[l2-i-1]=minus_s2[i]-'0';
	for(int i=0;i<len;i++){
		minus_i1[i]-=minus_i2[i];
		if(minus_i1[i]<0){
			minus_i1[i]+=10;
			minus_i1[i+1]--;
		}
	}

	while(minus_i1[len-1]==0 and len>1)
		len--;//?0 
		
	for(int i=len-1;i>=0;i--)
		ans=ans+char(minus_i1[i]+'0');
	return ans;
}
/*
string prec_minus(char minus_s1[10100],char minus_s2[10100]){
	int minus_i1[10100],minus_i2[10100];
	int l1=strlen(minus_s1),l2=strlen(minus_s2);
	string ans="";
	int len=max(l1,l2);
	
	memset(minus_i1,0,sizeof(minus_i1));
	memset(minus_i2,0,sizeof(minus_i2));

	for(int i=l1-1;i>=0;i--)//???? char->int 
		minus_i1[l1-i-1]=minus_s1[i]-'0';
	for(int i=l2-1;i>=0;i--)
		minus_i2[l2-i-1]=minus_s2[i]-'0';
	for(int i=0;i<len;i++){
		minus_i1[i]-=minus_i2[i];
		if(minus_i1[i]<0){
			minus_i1[i]+=10;
			minus_i1[i+1]--;
		}
	//	minus_i1[i+1]+=minus_i1[i]/10;//??
	//	minus_i1[i]%=10;
	}

	while(minus_i1[len-1]==0 and len>1)
		len--;//?0 
		
	for(int i=len-1;i>=0;i--)
		ans=ans+char(minus_i1[i]+'0');
	return ans;
}
*/
int main(){
	char s1[10100],s2[10100];
	while(cin>>s1>>s2)
		cout<<prec_minus(s1,s2)<<endl;
	return 0;
}


