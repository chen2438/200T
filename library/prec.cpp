#include<iostream>
#include<cstring>
using namespace std;

string prec_plus(string plus_s1,string plus_s2){
	int plus_i1[10100],plus_i2[10100];
	int l1=plus_s1.length(),l2=plus_s2.length();
	string ans="";
	int len=max(l1,l2);
	memset(plus_i1,0,sizeof(plus_i1));
	memset(plus_i2,0,sizeof(plus_i2));
	for(int i=l1-1;i>=0;i--)
		plus_i1[l1-i-1]=plus_s1[i]-'0';
	for(int i=l2-1;i>=0;i--)
		plus_i2[l2-i-1]=plus_s2[i]-'0';
	for(int i=0;i<len;i++){
		plus_i1[i]+=plus_i2[i];
		plus_i1[i+1]+=plus_i1[i]/10;
		plus_i1[i]%=10;
	}
	if(plus_i1[len]!=0) len++;
	while(plus_i1[len-1]==0 and len>1)
		len--;
	for(int i=len-1;i>=0;i--)
		ans=ans+char(plus_i1[i]+'0');
	return ans;
}

string prec_minus(string minus_s1,string minus_s2){ 
	int minus_i1[10100],minus_i2[10100];
	int l1=minus_s1.length(),l2=minus_s2.length();
	string ans="";
	int len=max(l1,l2);
	memset(minus_i1,0,sizeof(minus_i1));
	memset(minus_i2,0,sizeof(minus_i2));
	for(int i=l1-1;i>=0;i--)
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
		len--;
	for(int i=len-1;i>=0;i--)
		ans=ans+char(minus_i1[i]+'0');
	return ans;
}

string prec_multiply(string multiply_s1,string multiply_s2){ 
	int multiply_i1[1010],multiply_i2[1010],multiply_i3[1010];
	int l1=multiply_s1.length(),l2=multiply_s2.length();
	string ans="";
	int len=(l1+l2);
	memset(multiply_i1,0,sizeof(multiply_i1));
	memset(multiply_i2,0,sizeof(multiply_i2));
	memset(multiply_i3,0,sizeof(multiply_i3));
	for(int i=l1-1;i>=0;i--)
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
		len--;
	for(int i=len-1;i>=0;i--)
		ans=ans+char(multiply_i3[i]+'0');
	return ans;
}

string prec_division(string div_s1,int div_i2){
	int div_i1[10100];
	memset(div_i1,0,sizeof(div_i1));
	int l1=div_s1.length();
	for(int i=0;i<l1;i++)
		div_i1[i]=div_s1[i]-'0';
	int div_t=0;
	for(int i=0;i<l1;i++){
		div_t=div_t*10+div_i1[i];
		div_i1[i]=div_t/div_i2;
		div_t%=div_i2;
	}
	bool div_f=false;
	string ans;
	for(int i=0;i<l1;i++){
		if(div_i1[i]) div_f=true;
		if(div_f or i==l1-1) ans=ans+char(div_i1[i]+'0');
	}
	return ans;
}

