#include<iostream>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;

string int2str1(int num){
	stringstream str1;
	str1<<num;
	string str2;
	str2=str1.str();
	return str2;
} 

string int2str2(int num){
	string str2;
	str2=to_string(num);
	return str2;
}

int str2int1(string str1){
	istringstream str2(str1);
	int num;
	str2>>num;
	return num;
}

int str2int2(string str){
	int num;
	num=atoi(str.c_str());
	return num;
}



string d_to_oth(int n,int radix){
	int flag=-1;
	string ans="";
	if(n<0){
		flag=1;
		n=-n;
	}
	do{
		int t=n%radix;
		if(t>=0 and t<=9) ans+=t+'0';
		else ans+=t-10+'A';
		n/=radix;
	}while(n!=0);
	reverse(ans.begin(),ans.end());
	if(flag==1) ans="-"+ans; 
	return ans;	
}
int main(){
	
	return 0;
}

