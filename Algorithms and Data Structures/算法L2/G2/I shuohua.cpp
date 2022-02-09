#include<iostream>
#include<cstring>
#include<cmath>
#include<typeinfo>
#include<sstream>
#include<algorithm>
using namespace std;
string prec_multiply(string multiply_s1,string multiply_s2){ 
	int multiply_i1[1010],multiply_i2[1010],multiply_i3[1010];
	int l1=multiply_s1.length(),l2=multiply_s2.length();
	string ans="";
	int len=(l1+l2);
	
	memset(multiply_i1,0,sizeof(multiply_i1));
	memset(multiply_i2,0,sizeof(multiply_i2));
	memset(multiply_i3,0,sizeof(multiply_i3));
	
	for(int i=l1-1;i>=0;i--)//倒序赋值 char->int 
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
		len--;//去0 
		
	for(int i=len-1;i>=0;i--)
		ans=ans+char(multiply_i3[i]+'0');
	return ans;
}

string prec_plus(string plus_s1,string plus_s2){
	int plus_i1[1010],plus_i2[1010];
	int l1=plus_s1.length(),l2=plus_s2.length();
	string ans="";
	int len=max(l1,l2);
	
	memset(plus_i1,0,sizeof(plus_i1));
	memset(plus_i2,0,sizeof(plus_i2));

	for(int i=l1-1;i>=0;i--)//倒序赋值 char->int 
		plus_i1[l1-i-1]=plus_s1[i]-'0';
	for(int i=l2-1;i>=0;i--)
		plus_i2[l2-i-1]=plus_s2[i]-'0';
	for(int i=0;i<len;i++){
		plus_i1[i]+=plus_i2[i];
		plus_i1[i+1]+=plus_i1[i]/10;//进位
		plus_i1[i]%=10;
	}
	if(plus_i1[len]!=0) len++;//判断首位是否进位 

	while(plus_i1[len-1]==0 and len>1)
		len--;//去0 
		
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

	for(int i=l1-1;i>=0;i--)//倒序赋值 char->int 
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
		len--;//去0 
		
	for(int i=len-1;i>=0;i--)
		ans=ans+char(minus_i1[i]+'0');
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

string str2int(string s){
	string ans="0",bit,index;
	for(int i=s.length()-1;i>=0;i--){
		stringstream tbit;
		tbit<<s[i]-'a'+1;
		bit=tbit.str();
		index="1";
		for(int j=0;j<s.length()-i-1;j++){
			index=prec_multiply(index,"26");
		}
		ans=prec_plus(ans,prec_multiply(bit,index));
	}
	return ans;
}

string prec_mold_26(string mold_s1){
	return prec_minus( mold_s1,prec_multiply( prec_division(mold_s1,26),"26" ) );;
} 

string int2str(string s){
	string ans="";
	string rmd1=prec_mold_26(s);
	string dvs=prec_division(s,26);
	if(rmd1=="0"){
		ans+='z';
		dvs=prec_minus(dvs,"1");
	}
	else{
		istringstream rmdt(rmd1);
		int rmdi;
		rmdt>>rmdi;
		ans+=rmdi+'a'-1;
	}
	while(dvs>"0"){
		string rmd2=prec_mold_26(dvs);
		if(rmd2=="0"){
			ans+='z';
		}
		else{
			istringstream rmdt(rmd2);
			int rmdi;
			rmdt>>rmdi;
			ans+=rmdi+'a'-1;
		}
		dvs=prec_division(dvs,26);
	}
	reverse(ans.begin(),ans.end());
	return ans;	
}

string comma(string s){
	string ans;
	int cnt=-2;
	for(int i=s.length();i>=0;i--){
		cnt++;
		if(cnt==3){
			cnt=0;
			ans+=",";
			ans+=s[i];
		}
		else ans+=s[i];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	string t,ans;
	while(cin>>t){
		if(t[0]=='*')break;
		if(t[0]>='a' and t[0]<='z'){
			cout<<t;
			for(int i=0;i<22-t.length();i++)putchar(' ');
			ans=str2int(t);
			//ans=comma(ans);
			for(int i=0;i<ans.length()-1;i++)putchar(ans[i]);
			cout<<endl;
		}
		else{
			ans=int2str(t);
			cout<<ans;
			for(int i=0;i<22-ans.length();i++)putchar(' ');
			//t=comma(t);
			for(int i=0;i<t.length()-1;i++)putchar(t[i]);
			cout<<endl;
		}
	}
	return 0;
}
